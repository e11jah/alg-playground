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

const ll N = 1e6 + 1;
const ll mod = 1e9 + 7;

ll n, m;
vector<string> pic;

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

bool check(ll x, ll y)
{
    if (pic[x][y] != '.')
        return false;

    ll xx, yy, c = 0;
    FOR(i, 0, 3)
    {
        xx = x + dx[i], yy = y + dy[i];
        if (xx < 0 || xx >= n || yy < 0 || yy >= m)
            continue;
        if (pic[xx][yy] == '.')
            c++;
    }

    return c < 2;
}

void dfs(ll x, ll y)
{
    ll xx, yy;
    FOR(i, 0, 3)
    {
        xx = x + dx[i];
        yy = y + dy[i];
        if (xx < 0 || xx >= n || yy < 0 || yy >= m)
            continue;
        if (check(xx, yy))
        {
            pic[xx][yy] = '+';
            dfs(xx, yy);
        }
    }
}

int main()
{
    char cc;
    ll t, x, y, h, k, l, r, c, s, mi, ma, tot;
    RLL(t);

    P pos;
loop:
    while (t--)
    {
        RLL2(n, m);
        c = 0;
        pic.clear();
        pic.resize(n);

        FOR(i, 0, n - 1)
        FOR(j, 0, m - 1)
        {
            cin >> cc;
            pic[i].push_back(cc);
            if (cc == 'L')
                x = i, y = j;
        }
        dfs(x,y);

        FOR(i, 0, n - 1)
        {
            FOR(j, 0, m - 1)
            PC(pic[i][j]);
            PS("");
        }
    }
}