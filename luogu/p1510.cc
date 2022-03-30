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

const ll N = 1e5 + 10;
const ll MOD = 1e9 + 7;

bool isPrime(ll x) {
    if (x < 2)
        return false;
    FOR(i,2,sqrtl(x))
        if (x%i==0)
            return false;
    return true;
}

// 精卫填海 01 背包 + 求消耗
void solve()
{
    ll v,n,c, f[N], a,b,ans;
    RLL3(v,n,c);
    MM(f,0);
    FOR(i,1,n) {
        RLL2(a,b);
        for (ll j = c;j>=b;j--) {
            f[j]=max(f[j],f[j-b]+a);
        }
    }
    if (f[c]<v) {
        PS("Impossible");
        return;
    }
    // 二分找要填的体积
    ll used = lower_bound(f+1,f+1+c,v)-f;
    PLN(c-used);
}

int main()
{
    solve();
    return 0;
}