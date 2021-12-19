//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

using PII = pair<int, int>;
typedef long long ll;

int ans = INT32_MAX, arr[6][11], memo[26][6], path[6], minPath[6];

void dfs(int km, int p, int t) {
    if (km < 0)
        return;
    // 记忆化
    if (memo[km][p] < t)
        return;
    if (p > 5) {
        if (km == 0 && t < ans) {
            // 更新最优 dfs 路径
            for (int i = 1; i < 6; i++)
                minPath[i] = path[i];
            ans = t < ans ? t : ans;
        }
        return;
    }
    // 剩 km 公里时 p 个人参加的最小开销
    memo[km][p] = t;

    for (int i = 1; i <= 10; i++) {
        // 当前选手跑了 i 公里
        path[p] = i;
        dfs(km - i, p + 1, t + arr[p][i]);
    }
}

int main() {
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 6; j++)
            memo[i][j] = INT32_MAX;

    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 10; j++)
            cin >> arr[i][j];

    dfs(25, 1, 0);
    cout << ans << endl;

    for (int i = 1; i <= 5; i++)
        cout << minPath[i] << " ";
    return 0;
}