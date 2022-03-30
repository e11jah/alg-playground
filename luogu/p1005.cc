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

__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
bool cmp(__int128 x, __int128 y) { return x > y; }

__int128 binpow(__int128 x, __int128 y) {
    __int128 r = 1;
    while (y) {
        if (y%2) r*=x;
        x*=x;
        y>>=1;
    }
    return r;
}

// 区间 dp 枚举左右端点 同 p2858
// __int128 读写、快速幂
void solve()
{
    ll n,m;
    __int128 ans=0,a[100],f[100][100];
    RLL2(n,m);

    FOR(i,1,n) {
        MM(f,0);
        FOR(j,1,m) {
            a[j]=read();
            f[j][j]=a[j]*binpow(2,m);
        }

        FOR(len,1,m-1) {
            for (ll l=1;l+len<=m;l++) {
                ll r = l+len, x=m-len;
                f[l][r]=max(f[l+1][r]+a[l]*binpow(2,x), f[l][r-1]+a[r]*binpow(2,x));
            }
        }
        ans+=f[1][m];

    }
    print(ans);
}

int main()
{
    solve();
    return 0;
}