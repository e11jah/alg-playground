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

ll dp[55][55];

// 涂色 区间 dp
void solve() {
    string target;
    cin>>target;
    ll n = target.size();
    FOR(i,0,n)
        FOR(j,0,n)
            dp[i][j]=i==j?1:55;
    FOR(len,1,n-1) {
        for (ll i = 0; i + len <=n; i++) {
            ll j = i+len;
            if (target[i]==target[j]) 
                dp[i][j]=min(dp[i+1][j],dp[i][j-1]);
                // dp[i][j]=len==2?1:min(min(dp[i+1][j],dp[i][j-1]),dp[i+1][j-1]+1);
            else for(ll k = i; k < j; k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);  
        }
    }
    PLN(dp[0][n-1]);
}

int main() {
    solve();
}
