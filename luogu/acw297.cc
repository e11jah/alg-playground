#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <math.h>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>

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

const ll N = 1e3 + 10;
const ll MOD = 1e9+7;

ll t,n,m,len,a[N],dis[N],tre[N][N],dp[N][N],ans;

inline ll low_bit(ll x) {
    return x & -x;
}

void add(ll idx, ll length, ll v) {
    for (ll k = idx; k <= len; k+= low_bit(k))
        tre[k][length]=(tre[k][length]+v)%MOD;
}

ll ask(ll idx, ll length) {
    ll ans=0;
    for (ll k=idx;k;k-=low_bit(k))
        ans = (ans + tre[k][length]) % MOD;
    return ans;
}
// 二维树状数组 + 离散化 + dp
void solve() {
    RLL(t);
    ll c=0,j;
    while (t--) {
        RLL2(n,m);
        FOR(i,1,n)
            RLL(a[i]),dis[i]=a[i];

        sort(dis+1, dis+n+1);
        len = unique(dis+1,dis+1+n)-dis-1;
        FOR(i,1,n)
            a[i]=lower_bound(dis+1,dis+1+len, a[i])-dis+1;

        ans = 0;
        MM(dp, 0);
        MM(tre, 0);

        FOR(i,1,n)
            // 设 dp[i,j] 为以 i 结尾且长度为 j 的单调上升子序列有多少个
            dp[i][1]=1;

        FOR(i,1,n) {
            // 不计算 m > i 的状态（长度超出）
            for (j=2; j<=min(i,m);j++)
                // 状态转移，长度减一，idx 减一
                dp[i][j] = (dp[i][j]+ask(a[i]-1,j-1)) % MOD;

            // 加上 以 i 结尾 长度为 m 的序列数
            ans = (ans+dp[i][m])%MOD;

            for (j=1;j<=min(i,m);j++)
                add(a[i],j,dp[i][j]);
        }

        printf("Case #%d: %lld\n", ++c,ans);
    }
}

int main()
{
    solve();
    return 0;
}