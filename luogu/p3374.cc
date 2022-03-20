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

ll n, m, sum[N];
int a[N];

int lowbit(int x) {
    // 取最低位 1 即其后所有 0
    return x&-x;
}

void add(int x, int k) {
    while (x<=n)
        sum[x]+=k,x+=lowbit(x);
}

ll ask(int x) {
    ll ans=0;
    while(x>=1)
        ans+=sum[x],x-=lowbit(x);
    return ans;
}

int main() {
    RLL2(n,m);  
    sum[0]=0;
    int t;
    FOR(i,1,n) {
        scanf("%d", &t);
        add(i,t);
    }

    ll op, a,b;
    FOR(i,1,m) {
        RLL3(op,a,b);
        if (op==1) {
            add(a,b);
        } else {
            PLN(ask(b)-ask(a-1));
        }
    }
}