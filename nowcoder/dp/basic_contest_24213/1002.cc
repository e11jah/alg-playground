#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

#define FOR(i,l,r) for(int i = l; i <= r; i++)

typedef long long ll;
const int N = 1e5+5, MOD=1e9+7;
ll n,m,f[N];
// https://ac.nowcoder.com/acm/contest/24213/1002
// 有 3 家外卖，不能连续 3 天点一样的外卖，求方案数
void solve() {
    cin>>n;
//     memset(f,0,sizeof f);
    // f[0][i] 第 i 天去 0 家 为 i-1 天方案数 和 i-2 天方案数之和
    // 所以要么 i-1 天不去 0 家: f[1][i-1]+f[2][i-1]
    // 要么 i-2 天不去: f[1][i-2]+f[2][i-2]
    // 0,1,2 方案数一样, 压缩成一维
    f[1]=3,f[2]=9;
    FOR(i,3,n) {
        f[i]=((f[i-1]*2)%MOD+(f[i-2]*2)%MOD)%MOD;
    }
    cout << f[n]<<endl;
}
int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}