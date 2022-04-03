
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> h, int l, int r) {
    if (l > r)
        return;

    cout << h[l][r] << " ";
    dfs(h, l,h[l][r]-1);
    dfs(h, h[l][r]+1, r);
}

// 区间 dp
int main() {
    int n, t;
    cin >> n;
    vector<int> p(n+1);

    vector<vector<int>> f(n+2, vector<int>(n+2, 1));
    vector<vector<int>> h(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        f[i][i]=p[i], h[i][i]=i;
    }
    for (int len = 1; len < n; len++) {
        for (int i = 1; i + len<=n;i++) {
            int j = i + len;
            for (int k = i; k <= j; k++) {

                // f[i, i-1] = 1
                t=f[i][k-1]*f[k+1][j]+f[k][k];
                if (t > f[i][j]) {
                    f[i][j]=t, h[i][j]=k;
                }
            }
        }
    }
    cout << f[1][n] << endl;
    dfs(h, 1,n);
    return 0;
}


