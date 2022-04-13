#include <string>

#include <vector>
#include <map>

using namespace std;

#define FOR(i, l, r) for (int i = l; i <= r; i++)

typedef unsigned long long ull;
const int P = 131;

class Solution {
public:
    ull get(int l, int r, vector<ull> &h, vector<ull> &p) {
        return h[r]-h[l-1]*p[r-l+1];
    }
    string longestPrefix(string s) {
        int n = s.size(),len=0;

        vector<ull> h(n+1), p(n+1,1);

        FOR(i,1,n) {
            h[i]=h[i-1]*P+s[i-1];
            p[i]=p[i-1]*P;
        }

        FOR(i,1,n) {
            // 不为自身且前缀==后缀
            if (i!=n&&h[i]==get(n-i+1,n,h,p)) 
                len=i;
        }
        return s.substr(0,len);
    }
};