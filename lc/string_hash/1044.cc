#include <vector>

#include <map>
#include <string>

using namespace std;

#define FOR(i, l, r) for (int i = l; i <= r; i++)

typedef unsigned long long ull;
const int P = 131;

class Solution
{
    int n, st;

public:
    ull get(int l, int r, vector<ull> &h, vector<ull> &p)
    {
        return h[r] - h[l - 1] * p[r - l + 1];
    }

    bool check(int len, vector<ull> &h, vector<ull> &p)
    {
        map<ull, int> vis;
        // 哈希 + 滑动窗口, 每次 check O(n)
        FOR(i, 1, n - len)
        {
            if (vis[get(i, i + len, h, p)])
            {
                st = i - 1;
                return true;
            }
            vis[get(i, i + len, h, p)]++;
        }
        return false;
    }
    // 最长重复字符串 二分 + hash
    string longestDupSubstring(string s)
    {
        n = s.size();
        vector<ull> h(n + 1), p(n + 1, 1);
        FOR(i, 1, n)
        {
            h[i] = h[i - 1] * P + s[i - 1];
            p[i] = p[i - 1] * P;
        }
        int l = 0, r = n, m, len = -1;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (check(m, h, p))
            {
                len = m, l = m + 1;
            }
            else
                r = m - 1;
        }
        if (len == -1)
            return "";

        return s.substr(st, len + 1);
    }
};