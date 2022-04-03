#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        // write code here
        int a = str1.size(), b=str2.size(),len=0, p1;
        if (a==0||b==0)
            return "-1";
        vector<vector<int>> f(a+1, vector<int>(b+1, 0));
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                f[i+1][j+1]=str1[i]==str2[j]?f[i][j]+1:0;
                if (f[i+1][j+1]>len)
                    len=f[i+1][j+1],p1=i+1;
            }
        }

        return str1.substr(p1-len,len);
    }
};