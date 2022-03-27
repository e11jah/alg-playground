#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <math.h>
#include <queue>
#include <algorithm>
#include <iostream>

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

const ll N = 1e6 + 5;
const ll MOD = 998244353998244353;

// 开树状数组维护离散化后的前缀和
ll n,t, m, mm, tre[N];

inline ll lowbit(ll x) {
    // 取最低位 1 即其后所有 0
    return x&-x;
}
// 从二分搜索前缀和区间转为搜索某一特定位置的前缀和
// coz sumr - suml-1 < t ==> suml-1 > sumr -t

// 在前缀和 x 的位置加 k 次，本题 1
void add(ll x, ll k) {
    while (x<=mm+1)
        tre[x]+=k,x+=lowbit(x);
}

ll ask(ll x) {
    ll ans=0;
    while(x)
        ans+=tre[x],x-=lowbit(x);
    return ans;
}

vector<ll> dis;
ll idx(ll x) {
    return lower_bound(dis.begin(), dis.end(), x)-dis.begin()+1;
}
// 树状数组 + 离散化
int main()
{
    RLL2(n, t);
    MM(tre, 0);

    ll sum[N], ans=0;
    sum[0]=0;
    dis.push_back(0);
    dis.push_back(-t);
    FOR(i, 1, n)
    {
        RLL(sum[i]);
        sum[i]+=sum[i-1];
        dis.push_back(sum[i]);
        dis.push_back(sum[i]-t);
    }

    sort(dis.begin(), dis.end());
    mm=dis.back();
    dis.erase(unique(dis.begin(), dis.end()), dis.end());
    // 最大值即树状数组上限
    mm=idx(mm);

    add(idx(sum[0]),1);
    FOR(i,1,n) {
        // 大于 sumi - t 的前缀和都满足，用当前总数 i 减去不符合的数对数量
        ans += i -ask(idx(sum[i]-t));
        add(idx(sum[i]),1);
    }

    PLN(ans);
}