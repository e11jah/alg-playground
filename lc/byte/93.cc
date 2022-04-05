#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

// 复原 IP 地址 回溯
class Solution
{
    int n;

public:
    void dfs(vector<string> &ans, string &s, string t, int step, int pos)
    {
        if (step == 4 && pos == n)
        {
            t.pop_back();
            ans.push_back(t);
            return;
        }
        if (pos >= n)
            return;
        t += s[pos];
        dfs(ans, s, t + ".", step + 1, pos + 1);

        if (s[pos] == '0' || pos == n - 1)
            return;
        t += s[pos + 1];
        dfs(ans, s, t + ".", step + 1, pos + 2);
        int x = stoi(s.substr(pos, 3));
        if (x > 255 || pos + 2 >= n)
            return;
        t += s[pos + 2];
        dfs(ans, s, t + ".", step + 1, pos + 3);
    }
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ans;
        n = s.size();
        dfs(ans, s, "", 0, 0);
        return ans;
    }
};

