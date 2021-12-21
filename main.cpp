//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

using PII = pair<int, int>;
typedef long long ll;


int main() {
    string a, b;
    cin >> a >> b;
    int an = a.size(), bn = b.size();
    vector<vector<int>> dp(an + 1, vector<int>(bn + 1));

    // 处理边界情况 dp[0][i], dp[i][0] 都需要 i 次操作
    for (int i = 0; i <= an; i++)
        dp[i][0] = i;
    for (int i = 0; i <= bn; i++)
        dp[0][i] = i;
    int c1, c2, c3;
    for (int i = 1; i <= an; i++) {
        for (int j = 1; j <= bn; j++) {
            // 字符相同无需操作
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else {
                // c1 删除 a 的第 i 个字符
                // c2 将字符串A的第i个字符替换成字符串B的第j个字符
                // c3 在字符串A末添加字符串B的第j个字符
                c1 = dp[i - 1][j] + 1, c2 = dp[i - 1][j - 1] + 1, c3 = dp[i][j - 1] + 1;
                dp[i][j] = c1 < c3 ? c1 : c3;
                dp[i][j] = dp[i][j] < c2 ? dp[i][j] : c2;
            }
        }
    }
    cout << dp[an][bn];
}