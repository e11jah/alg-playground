#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
#define FOR(i,l,r) for(int i = l; i <=r; i++)
#define RFOR(i,r,l) for(int i = r; i>=l; i--)
const ll N = 310;
ll row[N]={0},f[N];
void solve() {
    ll n,m;
    cin>>n>>m;
    memset(f,0x3f,sizeof f);
    f[0]=0;
    ll LMAX=f[1];
    FOR(i,1,n) {
        FOR(j,1,m)
            cin >> row[j];
        sort(row+1,row+1+m);
        // 前缀和
        FOR(j,1,m) row[j]+=row[j-1];
        // 第一天从 f[0]=0 推出购买 m 个糖果分别的最小费
        RFOR(k,n,i) {
            FOR(j,1,m) {
                // k 表示容量, 01 背包
                if (k-j>=0)
                    f[k]=min(f[k], f[k-j]+row[j]+j*j);

            }
        }
//         FOR(j,0,n) cout << f[j] << ' ';
//         cout << i << endl;
        
        // （每天最少一个糖果，所以不能有前面不购买的情况）保留前一天到 n 的数据 推
        FOR(j,0,i-1) f[j]=LMAX;
    }
    
    cout << f[n] <<"\n";
}

int main() {
    solve();
    return 0;
}