//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int mx[101][101], dis[101][101], r, c, m=0;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int dfs(int i, int j) {
    if (dis[i][j])
        return dis[i][j];
    dis[i][j] = 1;
    int x, y;
    for (int k = 0; k < 4; k++) {
        x = i+dx[k], y = j + dy[k];
        if (x < 0 || x >= r || y < 0 || y >= c
            || mx[i][j] <= mx[x][y])
            continue;
        dfs(x,y);
        dis[i][j] = max(dis[i][j], 1+dis[x][y]);
    }
    return dis[i][j];
}

int main() {
    memset(dis, 0, sizeof dis);
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < r; j++)
            cin >> mx[i][j];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            m = max(m, dfs(i, j));
    cout << m;
    return 0;
}