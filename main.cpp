//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

//bits/stdc++.h
int main() {
    ios::sync_with_stdio(false);
    int mx[2][1001];
    int r, m = 0, t;
    cin >> r;
    memset(mx, 0, sizeof mx);
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= i; j++) {
            cin >> t;
            mx[i&1][j] = t + max(mx[(i-1)&1][j], mx[(i-1)&1][j-1]);
            m = max(m, mx[i&1][j]);
        }

    cout << m;

    return 0;
}