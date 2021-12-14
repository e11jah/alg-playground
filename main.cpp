//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int mx[1001][1001];
    memset(mx, 0, sizeof mx);
    int x1, y1, x2, y2;
    for (int i =0 ; i< m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1 - 1; x < x2; x++)
            for (int y = y1 - 1; y < y2; y++)
                mx[x][y]++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mx[i][j] << " ";
        cout << endl;
    }

    return 0;
}