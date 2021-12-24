//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

using PII = pair<int, int>;
typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    int n, m, v, p, q;
    cin >> n >> m;
    vector<PII> pp(m + 1);
    vector<vector<PII>> aa(m + 1);
    ll dp[n + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i < m; i++) {
        cin >> v >> p >> q;
        if (!q) {
            // 先计算价值 v 与 开销 w
            pp[i + 1].first = v * p, pp[i + 1].second = v;
        } else {
            aa[q].emplace_back(v * p, v);
        }
    }
    PII t, a1, a2;
    for (int i = 1; i <= m; i++) {
        t = pp[i];
        for (int j = n; t.second > 0 && j >= t.second; j -= 10) {
            dp[j] = max(dp[j], dp[j - t.second] + t.first);
            if (aa[i].empty())
                continue;
            a1 = aa[i][0], a2 = aa[i][1];
            if (j >= t.second + a1.second)
                dp[j] = max(dp[j], dp[j - t.second - a1.second] + t.first + a1.first);
            if (j >= t.second + a2.second)
                dp[j] = max(dp[j], dp[j - t.second - a2.second] + t.first + a2.first);
            if (j >= t.second + a1.second + a2.second)
                dp[j] = max(dp[j], dp[j - t.second - a1.second-a2.second] + t.first + a1.first + a2.first) ;
        }
    }
    cout << dp[n];
}