#include <iostream>

using namespace std;

int r, c;
char mx[101][101];
int visit_[101][101] = {0};
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int i, int j) {
    if (i < 0 || i >= r || j < 0 || j >= c)
        return;

    if (visit_[i][j])
        return;
    visit_[i][j] = 1;

    int x, y, cnt = 0;
    for (int k = 0; k < 8; k++) {
        x = i + dx[k];
        y = j + dy[k];
        if (x >= 0 && x < r && y >= 0 && y < c && mx[x][y] == '*') {
            cnt++;
        }
        dfs(x, y);
    }
    if (mx[i][j] != '*')
        mx[i][j] = char('0' + cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> mx[i][j];

    dfs(0, 0);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << mx[i][j];
        cout << endl;
    }
    return 0;
}
