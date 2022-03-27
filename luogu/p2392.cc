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

const ll N = 1e3 + 10;
const ll MOD = 1e9 + 7;

void solve()
{
    // sum 累加所有题目时间, f 开20*60以上
    ll s[4], ans = 0, a[100], f[2000], sum;
    RLL4(s[0], s[1], s[2], s[3]);
    FOR(i, 0, 3)
    {
        MM(f, 0);

        sum = 0;
        FOR(j, 1, s[i])
        {
            RLL(a[j]);
            sum += a[j];
        }
        FOR(j, 1, s[i])
        {
            for (ll k = sum / 2; k >= a[j]; k--)
                f[k] = max(f[k], f[k - a[j]] + a[j]);
        }
        ans += sum - f[sum / 2];
    }

    PLN(ans);
}
// 01 背包
int main()
{
    solve();
    return 0;
}