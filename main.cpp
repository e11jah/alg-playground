//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

using PII = pair<int, int>;
typedef long long ll;


int main() {
    int mx[1001][1001], n, m, c;
    vector<vector<ll>> sum(1001, vector<ll>(1001, 0ll));
    cin >> n >> m >> c;
    ll val = 0, t;
    memset(mx, 0, sizeof mx);
    /**
     * sum i,j =  sum i-1,j + sum i,j-1 - sum i-1,j-1 + a i,j
     * sum x2,y2 - sum x1-1,y2 - sum x2,y1-1 + sum x1-1,y1-1
     */
    int x1, y1, x, y;
    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mx[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + mx[i][j];
            if (i >= c && j >= c) {
                // x1, x2 已经为 左上角 -1
                x1 = i-c, y1 = j-c;
                t = sum[i][j] - sum[x1][j] - sum[i][y1] + sum[x1][y1];

                if (t > val)
                    x = x1+1, y = y1+1;
                val = val > t ? val : t;
            }
        }
    }
    cout << x << " " << y;

    return 0;
}