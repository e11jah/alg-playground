#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
#define FOR(i,l,r) for(int i = l; i <=r; i++)
#define RFOR(i,r,l) for(int i = r; i>=l; i--)

const int N = 2e2+5;

ll f[N][N]={0}, h[N],t[N];
void solve() {
    int n;
    cin >> n;
    // 断环成链
    FOR(i,1,n) 
        cin >> h[i],h[i+n]=h[i];
    FOR(i,1,2*n-1)
        t[i]=h[i+1];
    t[2*n]=h[1];

    ll ans = 0;
    // 使用 h, t 标记, 直接用区间 dp 板子
    FOR(len,1,n-1) {
        FOR(i,1,2*n-len) {
            int j = i+len;
            FOR(k,i,j-1) {
                f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+h[i]*t[k]*t[j]);
//                 ans=max(ans,f[i][j]);
            }
        }
    }

    FOR(i,1,n)
        ans=max(ans,f[i][i+n-1]);
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}