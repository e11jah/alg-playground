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
typedef pair<double, double> PDD;

const ll N = 1e3 + 10;
const ll MOD = 1e9 + 7;

PDD a[N];
void solve() {
    int n, d,x,y;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> x>>y;
        if (y > d) {
            cout << -1;
            return;
        }
        // 勾股定理，计算 以小岛为圆心，半径为 d 的圆在 x 轴上的弦的一半
        auto t=sqrt(d*d-y*y);
        a[i].first=x-t,a[i].second=x+t;
    }
        
    sort(a+1, a+n+1, [](const PDD l, const PDD r) {
        return l.second < r.second;
    });
    // 必须使用 double
    double ans=0,prev=-1e10;
    for (int i = 1; i <= n; i++ ) {
        if (a[i].first > prev)
            ans++,prev=a[i].second;
    }
    cout << ans;
}

int main() {
    solve();
    return 0;
}