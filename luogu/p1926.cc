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

ll n,m,k,r, a[12], w[12], p[12],dp[160];

// 01 背包
void solve() {
    MM(dp,0);
    RLL4(n,m,k,r);
    FOR(i,1,n)
        RLL(a[i]);
    sort(a+1,a+1+n);
    FOR(i,1,m)
        RLL(w[i]);

    FOR(i,1,m)
        RLL(p[i]);

    // 01 背包
    FOR(i,1,m)
        for (ll j = r; j >= w[i];j--)
            dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
    ll rest=r,c=0;  
    FOR(i,1,r)
        if (dp[i]>=k) {
            rest-=i;
            break;
        }
    // cout << "re "<<rest<<endl;
    FOR(i,1,n) {
        rest -= a[i];
        if (rest<=0)
            break;
        c++;
    }
    PLN(c);
}

int main() {
    solve();
    return 0;
}