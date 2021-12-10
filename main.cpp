//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int c[21][21], m[21], v[21], path[21], n;

int dfs(int i) {
    if (m[i])
        return m[i];

    m[i] = v[i];

    int t;
    for (int k = 1; k <= n; k++) {
        if (c[i][k]) {
            dfs(k);
            t = v[i] + m[k];
            if (t > m[i])
                // path[idx] 记录下一个最大的地窖
                path[i] = k;
            m[i] = max(m[i],t);
        }
    }

    return m[i];
}

int main() {
    memset(c, 0, sizeof c);
    cin >> n;
    for (int i = 1; i <=n; i++)
        cin >> v[i];

    for (int i = 1; i < n; i++)
        for (int j = i+1; j <= n; j++)
            cin >> c[i][j];
    int t, s, res = 0;
    for (int i= 1; i <= n; i++) {
        t = dfs(i);
        if (t > res) {
            res = t;
            s = i;
        }
    }
    for (int i = s; i != 0;) {
        cout << i << " ";
        i = path[i];
    }
    cout << endl << res;
    return 0;
}