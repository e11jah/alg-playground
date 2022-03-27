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

// 二维 01 背包
int main() {
    ll v,w,n, a[55][3],dp[410][410];
    RLL2(v,w);

    RLL(n);
    MM(dp,0);
    FOR(i,1,n) {
        RLL3(a[i][0],a[i][1],a[i][2]);
        for (ll j=v; j >= a[i][0];j--) 
            for (ll k=w; k >= a[i][1]; k--)
                dp[j][k] = max(dp[j][k], dp[j-a[i][0]][k-a[i][1]]+a[i][2]);
    }

    PLN(dp[v][w]);
}