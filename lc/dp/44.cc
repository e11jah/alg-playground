#include <iostream>
#include <string>
#include <vector>
using namespace std;

static const auto io_sync_off = []()
{
    // turn off sync
    ios::sync_with_stdio(false);
    // untie in/out streams
    cin.tie(nullptr);
    return nullptr;
}();

typedef long long ll;
#define FOR(i,l,r) for(int i = l; i <=r; i++)
#define RFOR(i,r,l) for(int i = r; i>=l; i--)

class Solution {
public:
    // 字符串通配符匹配
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> f(n+1, vector<bool>(m+1));
        f[0][0]=true;
        FOR(i,1,m)
            if (p[i-1]=='*')
                f[0][i]=f[0][i-1];

        FOR(i,1,n) {
            FOR(j,1,m) {
                
                if (p[j-1]=='*')
                    // 匹配 0/1/n 次
                    f[i][j]=f[i][j-1]||f[i-1][j-1]||f[i-1][j];
                else 
                    f[i][j]=f[i-1][j-1]&&(s[i-1]==p[j-1]||p[j-1]=='?');
            }
        }

        return f[n][m];
    }
};