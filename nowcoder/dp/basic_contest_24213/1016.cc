#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
#define FOR(i,l,r) for(int i = l; i <=r; i++)
#define RFOR(i,r,l) for(int i = r; i>=l; i--)
const ll N = 1e4+5, M=105;
ll f[M][N]={0}, w[N];

void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    memset(f, -0x3f, sizeof f);
    FOR(i,1,n) {
        cin >> w[i];
        f[1][i]=max(w[i],f[1][i-1]);
    }
    
    FOR(i,2,m) {
        FOR(j,(i-1)*k,n) {
            // i 背包容量, j 上一个物品位置
            f[i][j]=max(f[i][j-1], f[i-1][j-k]+w[j]);
        }
    }
    cout << f[m][n];
    
}

int main() {
    solve();
    return 0;
}