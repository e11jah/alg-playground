//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

using PII = pair<int, int>;
typedef long long ll;


#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
int main() {
    ios::sync_with_stdio(false);

    int n, r, N = 110, dp[N][N][2], ans = 0;
    cin >> n;
//    memset(dp, 0, sizeof dp);
//    fill(&dp[0][0][0], &dp[N - 1][N - 1][1], INT_MIN);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dp[i][j][0] = INT_MAX, dp[i][j][1] = INT_MIN;

    char op[N];
    for (int i = 1; i <= n; i++) {
        cin >> op[i] >> dp[i][i][0];
        op[i+n] = op[i];
        dp[i + n][i + n][0] = dp[i + n][i + n][1] = dp[i][i][1] = dp[i][i][0];
    }

    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= 2 * n; l++) {
            r = l + len - 1;
            for (int k = l; k < r; k++) {

                if (op[k + 1] == 't') {
                    dp[l][r][0] = min(dp[l][r][0], dp[l][k][0] + dp[k + 1][r][0]);
                    dp[l][r][1] = max(dp[l][r][1], dp[l][k][1] + dp[k + 1][r][1]);
                } else {
                    // 正负相乘得最小
                    dp[l][r][0] = min3(dp[l][r][0], dp[l][k][1] * dp[k + 1][r][0], dp[l][k][0] * dp[k + 1][r][1]);
                    // 负负、正正得最大
                    dp[l][r][1] = max3(dp[l][r][1], dp[l][k][1] * dp[k + 1][r][1], dp[l][k][0] * dp[k + 1][r][0]);
                }
//                printf("dp[%d][%d]: %d; dp[%d][%d]: %d, dp[%d][%d]: %d, k:%d, op: %c, v: %d\n", l, r, dp[l][r],
//                       l, k, dp[l][k], k + 1, r, dp[k + 1][r],
//                       k, op[k+1], t);
            }
        }
    }

    for (int i = 1; i < n; i++)
        ans = max(ans, dp[i][i + n - 1][1]);
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        if (dp[i][i+n-1][1] == ans)
            cout << i << " ";
}