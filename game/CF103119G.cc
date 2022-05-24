#include <iostream>
#include <functional>
#include <map>
#include <cstring>
#include <vector>
#include <unordered_map>

#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define RFOR(i, r, l) for (int i = r; i >= l; i--)

const int N = 4e5 + 5, M=260;

using namespace std;
int last[M],vis[M],winner[M],a[N];
const int Grammy = 1, Alice = 0;
vector<vector<int>> g(M);

void solve()
{
    FOR(i,0,255) 
        FOR(j,0,7) 
            g[i].push_back(i^1<<j);

    int n, m, op, x;
    cin >> n >> m;
    FOR(i, 1, n)
    cin >> a[i], last[a[i]]=i;

    function<bool(int)> dfs;
    dfs = [&](int idx) -> bool {
        if (vis[a[idx]]) return winner[a[idx]];
        vis[a[idx]]++;
        bool ok = 0;
        for (int x : g[a[idx]]) {
            if (last[x]>idx)
                // 能走到必败就是必胜，所有点都走不到必胜就是必败
                ok |= !dfs(last[x]);
        }
        return winner[a[idx]]=ok;
    };

    while (m--)
    {
        cin >> op >> x;
        if (op == 1)
        {
            a[++n]=x,last[x]=n;
            continue;
        }
        if (last[a[x]]!=x) {
            puts("Grammy");
            continue;
        }
        memset(vis,0,sizeof vis),memset(winner,0,sizeof winner);
        puts(dfs(x)? "Grammy" : "Alice");
    }
}

int main()
{
    solve();
    return 0;
}