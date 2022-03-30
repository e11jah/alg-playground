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

// 区间 dp + 倍增
void solve()
{
    ll n,ans=0,x;
    vector<int> f[60];
    RLL(n);
    FOR(i,0,59)
        f[i].resize(n+1);

    FOR(i,1,n) {
        RLL(x);
        f[x][i]=i+1;
    }
    // f[i][l]=r l 为左端点合成 i 的右端点 = r
    // f[i][l]=f[i-1][f[i-1][l]]
    // 262144 = 2^18, 1<=a[i]<=40, maxVal=58
    FOR(i,2,58) {
        FOR(j,1,n) {
            if (!f[i][j])
                f[i][j]=f[i-1][f[i-1][j]];
            if (f[i][j])
                ans=i;
        }
    }
    PLN(ans);
}

int main()
{
    solve();
    return 0;
}