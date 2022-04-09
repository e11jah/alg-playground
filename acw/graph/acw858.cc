#include <iostream>
#include <cstring>

using namespace std;

const int N =505,INF=0x3f3f3f3f;

// 与 dijkstra 不同, dist[i] 表示 i 点到联通块的距离
int n, g[N][N], dist[N],st[N];

// 思想与 dijkstra 类似
int prim() {
    // 最小生成树权值之和
    int res=0;
    dist[1]=0;
    for (int i = 1; i <= n; i++) {
        int t = -1;
        // 类似 dijkstra 找最小点
        for (int j = 1; j <= n; j++) 
            // 遍历集合外的点
            if (!st[j]&&(t==-1||dist[t]>dist[j]))
                t=j;
        // 不连通，不构成生成树
        if (dist[t]==INF)
            return INF;
        // 第一个点之后的点加上权值
        if (i) res+=dist[t];

        // 放入集合
        st[t]=1;
        // 更新连通块以外的点到连通块的距离
        for (int j = 1; j <= n; j++)
                dist[j]=min(dist[j], g[t][j]);
    }
    return res;
}

void solve() {
    int m,u,v,w;
    cin >> n >> m;

    memset(dist, 0x3f, sizeof dist);
    memset(g, 0x3f, sizeof g);
    while (m--) {
        cin >> u>>v>>w;
        // 无向图
        g[u][v]=g[v][u]=min(g[u][v], w);
    }
    int t = prim();
    if (t==INF)
        puts("impossible");
    else
        cout << t;
}

int main() {
    solve();
    return 0;
}