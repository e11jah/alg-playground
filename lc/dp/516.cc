#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    // 区间 dp 计算回文子序列长度
    int longestPalindromeSubseq(string s) {
        int n = s.size(), ans=1;
        vector<vector<int>> f(n+1, vector<int>(n+1));
        for (int i = 1; i < n; i++)
            f[i][i]=1;
        for (int len=1; len<n;len++) {
            for (int i=1; i+len<=n;i++) {
                int j = i+len;
                if (s[i-1]==s[j-1]) {
                    f[i][j]=f[i+1][j-1]+2;
                // 可以删除字符
                } else f[i][j]=max(f[i+1][j], f[i][j-1]);
                ans=max(ans, f[i][j]);
            }
        }
        return ans;
    }
};