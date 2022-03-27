#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

const int N = 600;
#define MM(a, b) memset(a, b, sizeof(a));
#define FOR(x, a, b) for (ll x = a; x <= b; x++)
ll c, n, k, x[N], y[N], dis[2 * N], len, sum[N * 2][N * 2];

inline ll lowbit(ll x)
{
    return x & -x;
}

ll idx(ll x)
{
    return lower_bound(dis + 1, dis + 1 + len, x) - dis;
}

bool check(ll now)
{
    int x1 = 1, x2 = 1, y1 = 1, y2 = 1;
    for (; x2 <= len; x2++)
    {
        while (dis[x2] - dis[x1] + 1 > now)
            x1++;
        for (y1 = 1, y2 = 1; y2 <= len; y2++)
        {
            while (dis[y2] - dis[y1] + 1 > now)
                y1++;
            if (sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] >= c)
                return true;
        }
    }
    return false;
}

// 离散化 + 前缀和 + 二分
int main()
{
    scanf("%lld %lld", &c, &n);
    dis[0] = 0;
    k = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld %lld", &x[i], &y[i]);
        dis[k++] = x[i];
        dis[k++] = y[i];
    }

    sort(dis + 1, dis + k);
    len = unique(dis + 1, dis + 1 + 2 * n) - dis - 1;

    MM(sum, 0);
    FOR(i, 1, n)
    {
        sum[idx(x[i])][idx(y[i])]++;
    }
    // 前缀和预处理
    FOR(i, 1, len)
    FOR(j, 1, len)
    {
        sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        // printf("s %lld %lld %lld\n", i,j, sum[i][j]);
    }

    ll l, r, m, ans = 0;
    l = 1, r = 10000;
    while (l <= r)
    {
        m = (l + r) / 2;
        // printf("m %lld\n", m);
        if (check(m))
            r = m - 1, ans = m;
        else
            l = m + 1;
    }
    printf("%lld", ans);
}