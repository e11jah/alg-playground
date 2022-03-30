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
#include <climits>

#define PIN(n) printf("%d\n", n)
#define PLN(n) printf("%lld\n", n)
#define PLN2(a, b) printf("%lld %lld\n", a, b)
#define PLN3(a, b, c) printf("%lld %lld %lld\n", a, b, c)
#define PLN4(a, b, c, d) printf("%lld %lld %lld %lld\n", a, b, c, d)

#define RI(n) scanf("%d", &n)
#define RI2(a, b) scanf("%d %d", &a, &b)
#define RI3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define RI4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
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

const ll N = 3e5 + 10;
const ll MOD = 1e9 + 7;

map<ll,ll> cache;

// 区间 dp + 前缀和
void solve()
{
    ll n,t,sum[310],f[310][310];
    RLL(n);
    MM(f, 0x3f);
    sum[0]=0;
    FOR(i,1,n) {
        RLL(t);
        sum[i]=sum[i-1]+t;
        // 自己的代价 0
        f[i][i]=0;
    }

    FOR(len,1,n-1) {
        for (ll i =1; i +len<=n;i++) {
            ll j = i+len;
            FOR(k,i,j-1) 
                // 分为两个区间的合并代价+区间合并的代价
                f[i][j]=min(f[i][j], f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);   
        }
    }
    PLN(f[1][n]);
}

int main()
{
    solve();
    return 0;
}