#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <math.h>
#include <queue>
#include <iostream>

#define PLN(n) printf("%lld\n", n)
#define PLN2(a, b) printf("%lld %lld\n", a, b)
#define PLN3(a, b, c) printf("%lld %lld %lld\n", a, b, c)
#define PLN4(a, b, c, d) printf("%lld %lld %lld %lld\n", a, b, c, d)

#define RLL(n) scanf("%lld", &n)
#define RLL2(a, b) scanf("%lld %lld", &a, &b)
#define RLL3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define RLL4(a, b, c, d) scanf("%lld %lld %lld %lld", &a, &b, &c, &d)

#define PS(s) printf("%s\n", s)
#define MM(a, b) memset(a, b, sizeof(a));
#define FOR(x, a, b) for (ll x = a; x <= b; x++)

#define V vector<ll>
#define VP vector<P>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll N = 35;
const ll mod = 1e9 + 7;

ll n, k=0, dp[N][N], root[N][N];
unsigned char vis[N];
ll fri[N][2];
vector<int> conn[N];

void dfs(ll l, ll r) {
    if (l<1 || r>n || r<l || l>r)
        return;
    ll m = root[l][r];
    printf("%lld ", m);
    if (l == r)
        return;
    // printf("l %lld m %lld r %lld\n", l,m,r);
    dfs(l,m-1);
    dfs(m+1,r);
}

// 区间 dp
// 树形 dp
int main() {
    RLL(n);
    FOR(i,1,n) {
        RLL(dp[i][i]);
        root[i][i]=i;
    }

    ll j;
    FOR(len,1,n) {
        for(ll i=1;i+len<=n;i++) {
            j=i+len;
            dp[i][j]=dp[i][i]+dp[j][j];
            root[i][j]=i;
            FOR(k,i,j) {
                if (dp[i][j] < dp[i][k-1]*dp[k+1][j]+dp[k][k]) {
                    dp[i][j]=dp[i][k-1]*dp[k+1][j]+dp[k][k];
                    root[i][j]=k;
                }
            }
        }
    }
    PLN(dp[1][n]);
    dfs(1,n);
}