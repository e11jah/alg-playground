//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

using PII = pair<int, int>;
typedef long long ll;

struct Loc {
    int x, y, t;
};


int main() {

    ios::sync_with_stdio(false);
    int t, n, N = 1001, sec;

    int mx[N][N], visit[N][N], x, y, found;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    vector<PII> p(2 * N - 2);

    Loc l{};
    cin >> t;

    while (t--) {
        memset(mx, 0, sizeof mx);
        memset(visit, 0, sizeof visit);
        p.clear();
        queue<Loc> q;
        found = 0;

        cin >> n;
        for (int i = 1; i <= 2 * n - 2; i++)
            cin >> p[i].first >> p[i].second;

        q.push({1, 1, 0});
        // 标记起点
        visit[1][1] = 1;
        while (!q.empty()) {
            l = q.front();
            q.pop();
            if (l.x == n && l.y == n) {
                found = 1;
                break;
            }

            for (int k = 0; k < 4; k++) {
                x = l.x + dx[k], y = l.y + dy[k];
                if (x > 0 && x <= n && y > 0 && y <= n && visit[x][y] == 0) {
                    q.push({x, y, l.t + 1});
                    // 入队后标记访问，避免重复放入
                    visit[x][y] = 1;
                }
            }
            if (l.t > 0 && l.t <= 2 * n - 2)
                visit[p[l.t].first][p[l.t].second] = 1;
        }
        if (found)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

}