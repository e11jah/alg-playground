//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

using PII = pair<int, int>;
typedef long long ll;


// 大师
void unSolve() {
    int n, d, ans = 0, md = 20000, MOD = 998244353;
    cin >> n;
    vector<int> v(n + 1);
    // dp[i][j] 表示数到第 i 个数，且公差为 j 时有多少种方案
    vector<vector<int>> dp(n + 1, vector<int>(20001));

    for (int i = 1; i <= n; i++)
        cin >> v[i];

    for (int i = 1; i <= n; i++) {
        // 加上所有单塔的方案
        ans++;
        for (int j = i - 1; j; j--) {
            // 计算 i 与 j 的公差（加最大公差处理负数）
            d = v[i] - v[j];
            d = d < 0 ? d + md : d;
            // j 结尾的等差数列追加一个 i ，多一种方案（最长）
            // 以 i 结尾且上一个数是 j 的公差为 k 的等差数列数量是以 j 结尾公差为 k 的等差数列数加一
            dp[i][d] = (dp[i][d] + dp[j][d] + 1) % MOD;
            // 加上 i 与 j 构成 2 个塔的方案，多一个
            ans = (ans + dp[j][d] + 1) % MOD;
        }
    }
    cout << ans;
}

int main() {
    int n, m, MOD = 1e6 + 7;
    // 第 i 种，余 k 个位置, 摆 j 个
//    int dp[101][101][101];
    cin >> n >> m;

    // 多重背包
    int dp[101];
    memset(dp, 0, sizeof  dp);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // 不摆时有且仅有 1 种方案
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int k = m; k>=0; k--) {
            // 满足 j 不大于 ai && 余下的位置能够放 j 个
            for (int j = 1; j <= min(a[i], k); j++) {
                //背包 dp[i][j] = max(dp[i-1][j], dp[i-1][k-j] + v[i])
                // k-j = 0 时即 k 自己
                dp[k] = (dp[k] + dp[k-j]) % MOD;
            }
        }
    }
    cout << dp[m];
}