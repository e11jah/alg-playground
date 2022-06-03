
#include <iostream>

using namespace std;
#define FOR(i,l,r) for(int i = l; i <=r; i++)
const int N = 2e4+5;
bool f[N];
void solve() {
    int v,n,t,ans;
    cin>>v>>n;
    f[0]=true;
    FOR(i,1,n) {
        // f[i][j] = f[i-1][j] || f[i-1][j-v[j]]
        cin>>t;
        // 01 背包 逆序
        for (int j = v; j >= t; j--)
            f[j]=f[j]||f[j-t];
    }

    
    for (int i = v; i > 0; i--)
        if (f[i]) {
            ans=v-i;
            break;
        }
    cout << ans;
}
int main() {
    solve();
    return 0;
}