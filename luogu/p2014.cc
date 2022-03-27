#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

#define PLN(n) printf("%lld\n",n)
#define PLN2(a,b) printf("%lld %lld\n",a,b)
#define PLN3(a,b,c) printf("%lld %lld %lld\n",a,b,c)
#define PLN4(a,b,c,d) printf("%lld %lld %lld %lld\n",a,b,c,d)

#define RLL(n) scanf("%lld",&n)
#define RLL2(a,b) scanf("%lld %lld",&a,&b)
#define RLL3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define RLL4(a,b,c,d) scanf("%lld %lld %lld %lld",&a,&b,&c,&d)

#define MM(a,b) memset(a,b,sizeof(a));
#define FOR(x,a,b) for(ll x=a;x<=b;x++)

#define V vector<ll>
#define VP vector<P>

using namespace std;
// 树形 背包

typedef long long ll;
typedef pair<ll,ll> P;

const ll N = 301;
const ll mod = 1e9+7;
ll n, m;

// dp[x][y] 以 x 为 根节点的子树中选 y 门获得的最多学分
ll dp[N][N], s[N];
vector<int> children[N];

void dfs(int nod) {
    dp[nod][0] = 0;

    for (int child : children[nod]) {
        dfs(child);

        for (int t = m; t >= 0; t--)
            for (int l = t; l >= 0; l--)
                dp[nod][t] = max(dp[nod][t], dp[nod][t-l]+dp[child][l]);
    }
    if (nod != 0)
        for (int i = m; i > 0; i--)
            dp[nod][i] = dp[nod][i-1] + s[nod];
}
// 树形 dp
int main(){
    MM(dp, 0);
    ll k;
    RLL2(n, m);

    FOR(i,1,n){
        // k parent, s point
        RLL2(k, s[i]);
        children[k].push_back(i);
    }
    dfs(0);
    PLN(dp[0][m]);
}
