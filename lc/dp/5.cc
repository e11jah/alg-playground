#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int mlen=1,l=0,r,n=s.size();
        if (n<2) return s;
        string ans;
        vector<vector<int>> f(n+1, vector<int>(n+1, 0));
        for (int i = 1; i <= n; i++)
            f[i][i]=1;
        // 区间 dp
        for (int len = 1; len <n; len++) {
            for (int i = 1; i +len <= n; i++) {
                int j = i+len;
                if (s[i-1]==s[j-1]) {
                    // 特判长度 2, f[2][3]=2
                    if (len==1)
                        f[i][j]=2;
                    // 特判长度 3, 必为回文, 但子串不是回文
                    else if(len==2)
                        f[i][j]=3;
                    // 如果缩短的子串也是回文, 长度增加
                    else if (f[i+1][j-1]>0)
                        f[i][j]=f[i+1][j-1]+2;

                    if (f[i][j]>mlen)
                        mlen=f[i][j],l=i-1;
                }
            }
        }

        return s.substr(l,mlen);
    }
};