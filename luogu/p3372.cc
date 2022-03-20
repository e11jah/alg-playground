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

const ll N = 5e5 + 5;
const ll MOD = 998244353998244353;

// sum 维护 i 的前缀和
// a2 维护 sum(i*v[i])
ll n, w, sum[N], a2[N];
int a[N];

inline int lowbit(int x)
{
    // 取最低位 1 即其后所有 0
    return x & -x;
}

void add(int x, int k)
{
    ll v = x * k;
    while (x <= n)
    {
        sum[x] += k;
        a2[x] += v;
        x += lowbit(x);
    }
}

void addRange(int l, int r, int x)
{
    add(l, x);
    add(r + 1, -x);
}

ll ask(ll *a, int x)
{
    ll ans = 0;
    while (x)
        ans += a[x], x -= lowbit(x);
    return ans;
}

ll askRange(ll l, ll r)
{
    // (r+1)*Sum[r]-l*Sum[l-1]-(Sumi(r*v[r])-Sumi((l-1)*v[l]))
    return (r + 1) * ask(sum, r) - l * ask(sum, l - 1) - (ask(a2, r) - ask(a2, l - 1));
}

int main()
{
    RLL2(n, w);
    MM(sum, 0);
    MM(a2,0);
    ll t,pre=0;
    FOR(i, 1, n)
    {
        RLL(t);
        add(i,t-pre),pre=t;
    }

    int op;
    ll x, y, k;
    FOR(i, 1, w)
    {
        cin >> op;
        if (op == 1)
        {
            RLL3(x, y, k);
            addRange(x, y, k);

        }
        else
        {
            RLL2(x, y);
            PLN(askRange(x, y));
        }
    }
}