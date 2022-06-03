#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
#define FOR(i,l,r) for(int i = l; i <=r; i++)
#define RFOR(i,r,l) for(int i = r; i>=l; i--)
const ll N = 1e4+5, M=105;

// 购买 i 次中奖金额 j 的方案数
ll f[31][130]={0};
ll fpow(ll a, ll x) {
    ll r=1;
    while (x) {
        if (x&1) r*=a;
        a*=a;
        x>>=1;
    }
    return r;
}
ll gcd(ll a, ll b) {
    return b ? gcd(b,a%b) : a;
}
void solve() {
    int n;
    cin >> n;
    
    // 不买彩票的方案数 1
    f[0][0]=1;
    
    FOR(i,1,n) {
        // 金额范围 i~4*i
        FOR(j,i,4*i) {
            f[i][j]=f[i-1][j-1];
            if (j>1)
                f[i][j]+=f[i-1][j-2];
            if (j>2)
                f[i][j]+=f[i-1][j-3];
            if (j>3)
                f[i][j]+=f[i-1][j-4];
        }
    }

    ll a = 0;
    FOR(i,3*n,4*n)
        a+=f[n][i];
    ll b = fpow(4,n), t = gcd(a,b);
    cout << a/t << '/' << b/t;
}

int main() {
    solve();
    return 0;
}