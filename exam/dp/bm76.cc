
// 字符串正则匹配 双倍经验
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
        int n = str.size(), m = pattern.size();
        vector<vector<int>> f(n+1, vector<int>(m+1));
        f[0][0]=1;
        // 标记所有 * 匹配 0 次的情况
        // a*a*a*c*
        for (int i = 2; i <= m; i+=2)
            if (pattern[i-1]=='*')
                f[0][i]=f[0][i-2];
        for (int i = 1; i <= n; i++) {
            char sc = str[i-1];
            for (int j = 1; j <= m; j++) {
                char pc = pattern[j-1];
                // 枚举所有情况
                // 遇到 '.' 或相等
                if (sc==pc||pc=='.') f[i][j]=f[i-1][j-1];
                // * 匹配 0 次 取决于 patern 前一位匹配情况 f[i][j-2]
                // * 匹配 1 次 取决于 * 之前的字符与 str 匹配情况
                // f[i][j-1]
                // * 匹配 多 次 取决于 str 前一位匹配情况 以及 当前字符是否匹配 * 之前的字符
                // f[i-1][j]&&(s[i-1]==p[i-2]||p[i-2]=='.')
                else if (pc=='*') {
                    f[i][j]=f[i][j-2]||f[i][j-1]
                        ||f[i-1][j]&&(sc==pattern[j-2]||pattern[j-2]=='.');
                }
            }
        }
//         for (int i = 0; i <= n; i++){
//             for (int j = 0; j <= m; j++)
//                 cout<<f[i][j]<<' ';
//             cout << endl;
//         }
        return f[n][m];
    }
};