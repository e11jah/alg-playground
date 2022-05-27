#include <iostream>

using namespace std;

#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define RFOR(i, r, l) for (int i = r; i >= l; i--)

#define PLN(n) printf("%lld\n", n)
#define PLN2(a, b) printf("%lld %lld\n", a, b)
#define PLN3(a, b, c) printf("%lld %lld %lld\n", a, b, c)
#define PLN4(a, b, c, d) printf("%lld %lld %lld %lld\n", a, b, c, d)

#define PIN4(a, b, c, d) printf("%d %d %d %d\n", a, b, c, d)

typedef long long ll;
typedef pair<int, int> PII;


const ll N = 1e5 + 5, MOD = 1e9 + 7;

ll a[N], tree[N * 4], tag[N << 2];

inline ll ls(ll p)
{
    return p << 1;
}

inline ll rs(ll p)
{
    return p << 1 | 1;
}

inline void lazy(ll p, ll l, ll r, ll k)
{
    tag[p] += k;
    tree[p] += k * (r - l + 1);
}

inline void push_up(ll p)
{
    tree[p] = tree[ls(p)] + tree[rs(p)];
}

inline void push_down(ll p, ll l, ll r)
{
    ll mid = (l + r) >> 1;
    lazy(ls(p), l, mid, tag[p]);
    lazy(rs(p), mid + 1, r, tag[p]);
    tag[p] = 0;
}

void build(ll p, ll l, ll r)
{
    tag[p] = 0;
    if (l == r)
    {
        tree[p] = a[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(ls(p), l, mid), build(rs(p), mid + 1, r);
    push_up(p);
}

inline void update(ll ql, ll qr, ll l, ll r, ll p, ll k)
{
    if (ql <= l && r <= qr)
    {
        tree[p] += k * (r - l + 1);
        tag[p] += k;
        return;
    }
    push_down(p, l, r);
    ll mid = (l + r) >> 1;
    if (ql <= mid)
        update(ql, qr, l, mid, ls(p), k);
    if (qr > mid)
        update(ql, qr, mid + 1, r, rs(p), k);
    push_up(p);
}

inline ll query(ll ql, ll qr, ll l, ll r, ll p)
{
    ll ans = 0;
    if (ql <= l && r <= qr)
        return tree[p];

    ll mid = (l + r) >> 1;
    push_down(p, l, r);
    if (ql <= mid)
        ans+=query(ql, qr, l, mid, ls(p));
    if (qr > mid)
        ans+=query(ql, qr, mid + 1, r, rs(p));
    return ans;
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    FOR(i, 1, n)
    scanf("%lld", &a[i]);
    build(1, 1, n);
    ll op, x, y, k;
    while (m--)
    {
        scanf("%lld", &op);
        switch (op)
        {
        case 1:
            scanf("%lld %lld %lld", &x, &y, &k);
            update(x, y, 1, n, 1, k);
            break;
        case 2:
            scanf("%lld %lld", &x, &y);
            printf("%lld\n", query(x, y, 1, n, 1));
            break;
        }
    }
}

int main()
{
    int t = 1;
    while (t--)
        solve();
    return 0;
}