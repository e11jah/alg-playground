#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <math.h>
#include <queue>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>

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

const ll N = 2e5 + 5;
const ll MOD = 998244353998244353;

ll n,m,lang[N],voice[N],subt[N],len;
int idx(int x) {
    return lower_bound(lang+1,lang+len+1,x)-lang;
}

struct Movie {
    ll id;
    int voi;
    int subt;
};

// 离散化
int main () {
    RLL(n);
    ll a[N], c[N];
    FOR(i,1,n) {
        RLL(lang[i]);
        a[i]=lang[i];
    }
    
    // 离散化
    sort(lang+1,lang+1+n);
    // unique 返回不重复的元素的后一位 iter, len-=1
    len=unique(lang+1,lang+1+n)-lang-1;
    set<ll> s;
    FOR(i,1,len)
        s.insert(lang[i]);

    MM(c,0);
    FOR(i,1,n)
        c[idx(a[i])]+=1;

    RLL(m);
    vector<Movie> points(m+1);
    FOR(i,1,m) {
        RLL(voice[i]);
        points[i]=Movie{i,0,0};
        if (s.find(voice[i])!=s.end()) 
            points[i].voi=c[idx(voice[i])];
    }
    FOR(i,1,m) {
        RLL(subt[i]);
        if (s.find(subt[i])!=s.end())
            points[i].subt=c[idx(subt[i])];
    }

    sort(points.begin()+1,points.end(), [](const Movie & l, const Movie & r) {
        if (l.voi==r.voi)
            return l.subt < r.subt;
        return l.voi < r.voi;
    });

    PLN(points[m].id);
    return 0;
}