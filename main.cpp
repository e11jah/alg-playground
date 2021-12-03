#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 105;

void f1() {
    int t, r, c;
    cin >> t;
    int f[N][N], w[N][N];
    while (t--) {
        cin >> r >> c;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                cin >> w[i][j];
            }
        }

        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                f[i][j] = max(f[i - 1][j] + w[i][j], f[i][j - 1] + w[i][j]);

        cout << f[r][c] << endl;
    }
}

void f2() {
    int t, r, c;
    int w[2][N], f[2][N];
    memset(f, 0, sizeof f);
    cin >> t;
    while (t--) {
        cin >> r >> c;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                cin >> w[i & 1][j];
                f[i & 1][j] = max(f[(i - 1) & 1][j], f[i & 1][j - 1]) + w[i & 1][j];
            }
        }
        cout << f[r & 1][c] << endl;
        memset(f, 0, sizeof f);
    }
}

int main() {
    f2();
    return 0;
}
