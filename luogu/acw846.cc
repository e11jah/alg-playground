#include <iostream>
#include <cstring>
using namespace std;

// 树的重心
typedef long long ll;
const int N = 1e5 + 5;
// 边是节点数两倍
const int M =  2*N;

int n, ans = N, h[N], to[M], nex[M], vis[N], idx = 0;

void add(int a, int b)
{
    to[idx] = b;
    nex[idx] = h[a];
    h[a] = idx++;
}

// 返回以 u 为根的子树的节点数
int dfs(int u)
{
    vis[u] = 1;
    int s = 1, m = 0, t;
    for (int j = h[u]; j!=-1; j = nex[j])
    {
        if (vis[to[j]]==1)
            continue;
        t = dfs(to[j]);
        m = max(m, t);
        s += t;
    }
    // 计算根以上的部分的节点数
    m = max(m, n - s);
    ans = min(ans, m);

    return s;
}
// 树的重心
void solve()
{
    cin >> n;

    memset(h, -1, sizeof(h));
    memset(vis, 0, sizeof(vis));
    int x, y;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        add(x, y), add(y, x);
    }
    dfs(1);
    cout << ans;
}

int main()
{
    solve();
    return 0;
}