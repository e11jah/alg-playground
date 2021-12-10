//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

//bits/stdc++.h
int main() {
    ios::sync_with_stdio(false);
    int bx, by, hx, hy;
    cin >> bx >> by >> hx >> hy;

    // 🐴的范围：(hx +- 1, hy +- 2), (hx +- 2, hy += 1)
    long long dp[21][21];
    // 初始化 1, 用 vector 或者 memset
    bool vis[21][21];
    memset(dp, 0, sizeof dp);
    memset(vis, true, sizeof vis);

    int dx[8] = {-1, -1, -2, -2, 1, 1, 2, 2};
    int dy[8] = {-2, 2, -1, 1, -2, 2, -1, 1};
    int t1, t2;
    for (int i = 0; i < 8; i++) {
        t1 = hx + dx[i];
        t2 = hy + dy[i];
        if (t1 >= 0 && t1 < 21 && t2 >= 0 && t2 < 21)
            vis[t1][t2] = false;
    }
    vis[hx][hy] = false;

    // 只能向下或向右，两条边都是 1
    for (int j = 1; j <= by; j++) {
        if (j > 1 && !dp[0][j-1])
            continue;
        if (vis[0][j])
            dp[0][j] = 1;
    }
    for (int i = 1; i <= bx; i++) {
        if (i > 1 && !dp[i - 1][0])
            continue;
        if (vis[i][0])
            dp[i][0] = 1;
    }

    for (int i = 1; i <= bx; i++)
        for (int j = 1; j <= by; j++)
            if (vis[i][j])
                dp[i][j] = dp[i][j-1]+dp[i-1][j];
    cout << dp[bx][by] << endl;

    return 0;
}