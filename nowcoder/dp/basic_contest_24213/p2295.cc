#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
#define FOR(i,l,r) for(int i = l; i <=r; i++)
#define RFOR(i,r,l) for(int i = r; i>=l; i--)

const int N = 1e3+5;
int g[N][N]={0}, f[N][N][2];
void solve() {
    int n,m;
    cin >> n >> m;

    FOR(i,1,n)
        FOR(j,1,m)
            cin >> g[i][j];

    memset(f,0x3f,sizeof f);
    f[1][1][0]=f[1][1][1]=g[1][1]+g[1][2]+g[2][1];

    FOR(i,1,n) {
        FOR(j,1,m) {
            if (i==1&&j==1) continue;
            // 0 从左边过来, 到达左边之前可能从左边或者上边过来
            f[i][j][0]=min(f[i][j-1][0]+g[i-1][j], f[i][j-1][1])+g[i+1][j]+g[i][j+1];

            // 1 从上边过来
            f[i][j][1]=min(f[i-1][j][0], f[i-1][j][1]+g[i][j-1])+g[i+1][j]+g[i][j+1];
        }
    }
    cout << min(f[n][m][1],f[n][m][0]);
}

int main() {
    solve();
    return 0;
}