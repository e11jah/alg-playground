#include <iostream>
#include <vector>
//#include <algorithm>

using namespace std;

void f2() {
    int N = 501;
    int r;
    int w[N][N], f[N][N];
    memset(f, 0, sizeof f);

    cin >> r;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> w[i][j];
        }
    }

    for (int i = r; i > 0; i--)
        for (int j = 1; j <= i; j++)
            f[i][j] = max(f[i+1][j], f[i+1][j+1]) + w[i][j];


    cout << f[1][1] << endl;
}

int main() {
    f2();
    return 0;
}
