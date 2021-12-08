//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int mx[505][505];
int tmp[505][505];

void rotate_mx(int x, int y, int n) {
    if (n == 1)
        return;

    for (int i = x; i < x + n; i++)
        for (int j = y; j < y + n; j++)
            tmp[i][j] = mx[i][j];

    int x1 = x + n-1, y1 = y;
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            mx[i][j] = tmp[x1][y1];
            x1--;
        }
        x1 = x + n-1;
        y1++;
    }
}

void anticlockwise_rotate_mx(int x, int y, int n) {
    if (n == 1)
        return;

    for (int i = x; i < x + n; i++)
        for (int j = y; j < y + n; j++)
            tmp[i][j] = mx[i][j];

    int x1 = x, y1 = y + n-1;
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            mx[i][j] = tmp[x1][y1];
            x1++;
        }
        y1--;
        x1 = x;
    }
}

void print_mx(int x, int y, int n) {
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++)
            cout << mx[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

//bits/stdc++.h
int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    int t = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mx[i][j] = t++;

    int x, y, r, z;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> r >> z;
        if (!z)
            rotate_mx(x - r - 1, y - r - 1, 2 * r + 1);
        else
            anticlockwise_rotate_mx(x - r - 1, y - r - 1, 2 * r + 1);
    }
    print_mx(0, 0, n);
    return 0;
}