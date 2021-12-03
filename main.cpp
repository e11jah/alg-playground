#include <iostream>
#include <vector>
//#include <algorithm>

using namespace std;


void f2() {
    int N = 110;
    int w[N], v[N], dp[2][1100];

    memset(dp, 0, sizeof dp);
    int t, m;
    cin >> t >> m;
    /**
     * 表示 max 经验值 + 药数量
     * f[i][j] = max(f[i-1][j], f[) + w[i][j]
     */
    for (int i = 1; i <= m; i++)
        cin >> w[i] >> v[i];

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= t; j++) {
            if (j < w[i])
                dp[i & 1][j] = dp[(i - 1) & 1][j];
            else
                dp[i & 1][j] = max(dp[(i - 1) & 1][j], dp[(i - 1) & 1][j - w[i]] + v[i]);
        }
    }
    cout << dp[m & 1][t] << endl;
}

int main() {
    f2();
    return 0;
}
