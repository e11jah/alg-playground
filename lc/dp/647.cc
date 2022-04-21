#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    // 同  lc.5 
    int countSubstrings(string s) {
        int n=s.size(),ans=0;
        vector<vector<int>> f(n+1, vector<int>(n+1));
        // 区间 dp 标记是否回文串
        // 判断端点 枚举情况
        for (int len=1; len < n; len++) {
            for (int i = 1; i +len<=n; i++) {
                int j = i + len;
                if (s[i-1]==s[j-1]) {
                    if (len<3)
                        ans++, f[i][j]=1;
                    else if(f[i+1][j-1])
                        ans++,f[i][j]=1;
                }
            }
        }
        return ans+n;
    }
};