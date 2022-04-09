#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
// 区间 dp
void solve() {
    int n ;
    ll ans=0;
    cin >> n;
    vector<ll> a(n+1), b(n+1);
    vector<vector<ll>> f(n+1, vector<ll>(n+1));
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        f[i][i]=b[n]*a[i];
    int j, k, t;
    for (int len = 1; len < n; len++) {
        for (int i = 1; i + len <= n; i++) {
            j = i + len, k = n - len;
            // 比较这次取左 还是取右端点
            f[i][j]=max(f[i+1][j]+b[k]*a[i], f[i][j-1]+b[k]*a[j]);
        }
    }
    cout << f[1][n];
}

int main() {
    solve();
    return 0;
}