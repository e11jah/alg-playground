//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

using PII = pair<int, int>;
typedef long long ll;


const int N = 500;
int mx[N][N], vis[N][N], ans = INT_MAX, dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, int t) {
    if (x < 0 || y < 0 || t >= mx[x][y] || t >= ans || t >= vis[x][y])
        return;


    vis[x][y] = t;
    if (mx[x][y] == INT_MAX) {
        ans = ans > t ? t : ans;
        return;
    }
    for (int i = 0; i < 4; i++)
        dfs(x + dx[i], y + dy[i], t + 1);
}

int main() {

    ios::sync_with_stdio(false);
    fill(&mx[0][0], &mx[N - 1][N - 1], INT_MAX);
    fill(&vis[0][0], &vis[N - 1][N - 1], INT_MAX);

    int m;
    cin >> m;
    int x, y, t;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> t;
        mx[x][y] = min(mx[x][y], t);

        for (int j = 0; j < 4; j++)
            if (x + dx[j] >= 0 && y + dy[j] >= 0)
                mx[x + dx[j]][y+dy[j]] = min(mx[x+dx[j]][y+dy[j]], t);
    }
    dfs(0, 0, 0);
    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans;
}