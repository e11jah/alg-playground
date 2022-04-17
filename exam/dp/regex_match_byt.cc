#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * 
abedcad
*a*c*d
 * 
aa
a*
 * 
ab
a?
 * 
aasdxzcxasdx
a*x*x
 */
void solve() {
    string s, p;
    cin >> s >> p;
    int n = s.size(), m = p.size();
    vector<vector<int>> f(m+1, vector<int> (n+1));
    f[0][0]=1;
    for (int i = 1; i <= m; i++) {
        char pc = p[i-1];
        // 特判第一个字符 * 匹配空串
        f[i][0]=f[i-1][0]&&(pc=='*');
        for (int j = 1; j <= n; j++) {
            char sc = s[j-1];
            if (pc=='*')
                // i pc j sc
                // * 匹配多次, f[i][j-1] 前一位置匹配就匹配
                // patern 前一位匹配就匹配
                // * 匹配 0 次, f[i-1][j] 匹配就匹配
                f[i][j]=f[i-1][j]|f[i][j-1];
            else f[i][j]=f[i-1][j-1]&&(pc=='?'||pc==sc);
        }
    }
    cout << f[m][n];
}

int main() {
    solve();
    return 0;
}