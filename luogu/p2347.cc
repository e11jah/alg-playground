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

// 多重背包转 01 背包 求方案数
void solve()
{
    ll a[N], f[N], c,cur=1, sum=0,ans=0;
    int d[7] = {0,1,2,3,5,10,20};
    FOR(i,1,6) {
        RLL(c);
        // 入队
        FOR(j,1,c)
            a[cur++]=d[i],sum+=d[i];
    }
    MM(f,0);
    f[0]=1;
    // 设f[i][j]选i个为体积为j的方案数
    // 选： f[i][j]=f[i-1][j-w[i]]
    // 不选 f[i][j]=f[i-1][j]
    FOR(i,1,cur-1) {
        for (ll j = sum;j>=a[i];j--)
            f[j]+=f[j-a[i]];
    }
    // 枚举各个体积下是否有方案
    FOR(i,1,sum)
        if (f[i])
            ans++;
    printf("Total=%lld",ans);
}

int main()
{
    solve();
    return 0;
}