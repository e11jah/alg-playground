#include <cstdio>
#include <cstdlib>
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
// 树形 dp

typedef long long ll;
typedef pair<ll,ll> P;

const ll N = 6*1e3+1;
const ll mod = 1e9+7;
ll n, h[N], ind[N], vis[N], par[N], root;
// 当前节点不来，子节点随意
// dp[0][i] = max(dp[1][child], dp[0][child])
// 当前节点来，子节点不能来
// dp[1][i] = dp[0][child] + h[i]
ll dp[2][N];

void dfs(int nod) {
    if (!nod)
        return;
    vis[nod]=1;
    root=nod;
    dp[0][par[nod]]+=max(dp[1][nod]+h[nod], dp[0][nod]);
    dp[1][par[nod]]+=dp[0][nod];
    // 减去更新过的子节点
    ind[par[nod]]--;

    // 自底向上搜索，更新完子节点搜索父节点
    if (!ind[par[nod]])
        dfs(par[nod]);
}

int main(){
    ll l, k;
    RLL(n);

    FOR(i,1,n){
        // 高兴值
        RLL(h[i]);
    }
    FOR(i, 2, n) {
        RLL2(l, k);
        // 父节点
        par[l]=k;
        // 入度
        ind[k]++;
    }
    
    FOR(i, 1, n) {
        if (!vis[i]&&!ind[i])
            dfs(i);
    }
    PLN(max(dp[0][root], dp[1][root]+h[root]));
}
