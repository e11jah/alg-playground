#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <math.h>
#include <queue>
#include <algorithm>
#include <iostream>

#define PLN(n) printf("%lld\n", n)
#define PLN2(a, b) printf("%lld %lld\n", a, b)
#define PLN3(a, b, c) printf("%lld %lld %lld\n", a, b, c)
#define PLN4(a, b, c, d) printf("%lld %lld %lld %lld\n", a, b, c, d)

#define RLL(n) scanf("%lld", &n)
#define RLL2(a, b) scanf("%lld %lld", &a, &b)
#define RLL3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define RLL4(a, b, c, d) scanf("%lld %lld %lld %lld", &a, &b, &c, &d)

#define RS(n) scanf("%s", n)
#define PC(s) printf("%c", s)
#define PP() putchar(' ')
#define PS(s) printf("%s\n", s)
#define MM(a, b) memset(a, b, sizeof(a));
#define FOR(x, a, b) for (ll x = a; x <= b; x++)

#define V vector<ll>
#define VP vector<P>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll N = 5e5 + 5;
const ll MOD = 998244353;

ll n, m,dp[N][2];
vector<string> pic;

void solve()
{
    ll x,ans=-1;
    RLL(n);

    // dp[i] 表示 MEX 值为 i 的方案数
    // 0 1 表示序列中是否有比 MEX 值大的数字
    dp[0][0]=1;
    FOR(i,1,n) {
        RLL(x);
        // s=0, k=x+1, 可由 dp[x][0] 转移
        dp[x+1][0]=(2*dp[x+1][0]+dp[x][0])%MOD;
        // s=1,k=x+1, 遇到 x 任选, 方案数 * 2
        dp[x+1][1]=(2*dp[x+1][1])%MOD;
        if(x)
            // s=1, k=x-1, 可由 dp[x-1][0] 转移
            dp[x-1][1]=(2*dp[x-1][1]+dp[x-1][0])%MOD;
    }
    FOR(i,0,n+1) {
        // 任意 i, a[i] <= n，加上 i 存在或不存在的方案数
        ans=(ans+dp[i][0]+dp[i][1])%MOD;
        // clear dp
        dp[i][0]=dp[i][1]=0;
    }
    PLN(ans);
}

int main()
{
    char cc;
    ll t, x, y, h, k, l, r, c, s, mi, ma, tot;
    RLL(t);

loop:
    while (t--)
        solve();
}