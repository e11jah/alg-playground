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

const ll N = 1e5 + 5, MOD = 571373;

ll a[N], tree[N * 4], tadd[N << 2], tmul[N << 2], mod;

inline ll lc(ll p)
{
    return p << 1;
}
inline ll rc(ll p)
{
    return p << 1 | 1;
}

// 先 * 后 +
inline void lazy(ll p, ll l, ll r, ll mul, ll add)
{
    tmul[p] = (tmul[p] * mul) % mod;
    tadd[p] = (tadd[p] * mul + add) % mod;

    tree[p] = (tree[p] * mul + add * (r - l + 1)) % mod;
}

// lazy tag 计算
inline void push_down(ll p, ll l, ll r)
{
    ll mid = (l + r) >> 1;
    lazy(lc(p), l, mid, tmul[p], tadd[p]);
    lazy(rc(p), mid + 1, r, tmul[p], tadd[p]);
    tmul[p] = 1;
    tadd[p] = 0;
}

inline void push_up(ll p)
{
    tree[p] = (tree[lc(p)] + tree[rc(p)]) % mod;
}

void build(ll p, ll l, ll r)
{
    tmul[p] = 1, tadd[p] = 0;
    if (l == r)
    {
        tree[p] = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(lc(p), l, mid), build(rc(p), mid + 1, r);
    push_up(p);
}

inline void mul(ll ql, ll qr, ll l, ll r, ll p, ll k)
{
    // 查询区间和本区间无交集
    if (qr < l || ql > r)
        return;
    // 查询区间包含本区间
    if (ql <= l && qr >= r)
    {
        tree[p] = (tree[p] * k) % mod;
        tmul[p] = (tmul[p] * k) % mod;
        tadd[p] = (tadd[p] * k) % mod;
        return;
    }
    // 部分相交
    push_down(p, l, r);
    int m = (l + r) >> 1;
    mul(ql, qr, l, m, lc(p), k), mul(ql, qr, m + 1, r, rc(p), k);
    push_up(p);
}

inline void add(ll ql, ll qr, ll l, ll r, ll p, ll k)
{
    if (qr < l || ql > r)
        return;
    if (ql <= l && qr >= r)
    {
        tree[p] = (tree[p] + k * (r - l + 1)) % mod;
        tadd[p] = (tadd[p] + k) % mod;
        return;
    }
    push_down(p, l, r);
    int m = (l + r) >> 1;
    add(ql, qr, l, m, lc(p), k), add(ql, qr, m + 1, r, rc(p), k);
    push_up(p);
}

inline ll query(ll ql, ll qr, ll l, ll r, ll p)
{
    if (qr < l || ql > r)
        return 0;
    if (ql <= l && qr >= r)
        return tree[p];
    push_down(p, l, r);
    int m = (l + r) >> 1;
    return (query(ql, qr, l, m, lc(p)) + query(ql, qr, m + 1, r, rc(p))) % mod;
}

void solve()
{
    int n, m;
    cin >> n >> m >> mod;
    FOR(i, 1, n)
    cin >> a[i];

    build(1, 1, n);
    ll op, x, y, k;
    while (m--)
    {
        cin >> op >> x >> y;
        switch (op)
        {
        case 1:
            cin >> k;
            mul(x, y, 1, n, 1, k);
            break;
        case 2:
            cin >> k;
            add(x, y, 1, n, 1, k);
            break;
        case 3:
            cout << query(x, y, 1, n, 1) << endl;
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