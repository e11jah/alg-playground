
#include <string>
#include <vector>

using namespace std;

// dp 实现 正则匹配
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @param pattern string字符串 
     * @return bool布尔型
     */
    bool match(string str, string pattern) {
        // write code here
        int a=str.size(),b=pattern.size();
        vector<vector<int>> f(a+1, vector<int>(b+1,0));
        f[0][0]=1;
        // 初始化 s 为空的情况，遇到 * 转移到 x* 之前的匹配情况
        for (int i = 1; i <= b; i++)
            if (pattern[i-1]=='*')
                f[0][i]=f[0][i-2];
        for (int i =1; i<=a; i++) {
            for (int j =1; j<=b;j++) {
                if (str[i-1]==pattern[j-1]||pattern[j-1]=='.')
                    // 取决于前一位是否匹配
                    f[i][j]=f[i-1][j-1];
                else if (pattern[j-1]=='*') {
                    // 不看
                    if (j >=2) {
                        f[i][j]=f[i][j-2];
                        // 看 
                        if (pattern[j-2]==str[i-1]||pattern[j-2]=='.')
                            // 多出些一次或不出现
                            f[i][j] |= f[i-1][j];
                    }
                }
            }
        }
        return f[a][b];
    }
};