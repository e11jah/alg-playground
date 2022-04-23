#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

#define FOR(i,l,r) for(int i = l; i <= r; i++)

typedef long long ll;
int n,m,f[31][31];
void solve() {
    cin>>n>>m;
    memset(f,0,sizeof f);
    int t,k;
    f[0][1]=1;
    FOR(i,1,m) {
        FOR(j,1,n) {
            // 有环特判头尾
            t=j==1?n:j-1,k=j==n?1:j+1;
            // 转移方程
            // i 为传球轮次, j 为 n 号同学的左右, j+1,j-1
            f[i][j]=f[i-1][t]+f[i-1][k];
        }
    }
    cout << f[m][1];
}
int main() {
    solve();
    return 0;
}