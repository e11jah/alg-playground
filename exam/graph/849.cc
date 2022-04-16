#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;
// 稠密图用邻接矩阵存储
int g[N][N];
// dist 每个点到第一个点的距离
// st 记录该点的最短距离是否确定
int dist[N], st[N];
int n;
// dijkstra 单源最短路
int dijkstra() {
    // 初始化距离
    memset(dist, 0x3f, sizeof dist);
    // 1 到自身的距离 0
    dist[1]=0;
    // 遍历
    for (int i = 0; i < n; i++) {
        // 记录最近的点
        int t = -1;
        // 遍历
        for (int j=1;j<=n;j++)
            if (!st[j]&&(t==-1||dist[j]<dist[t]))
                t=j;
        // 剪枝
        if (t==n)
            break;
        st[t]=1;
        // 通过中间点更新最短距离
        for (int j = 1; j <= n; j++)
            dist[j]=min(dist[j], dist[t]+g[t][j]);
    }
    // 不可达
    if (dist[n]==0x3f3f3f3f)
        return -1;
    return dist[n];
}
void solve() {
    int m,x,y,z;
    cin >> n >> m;
    // 每个字节 0x3f, 设置为无穷大
    memset(g, 0x3f, sizeof g);

    while(m--) {
        cin >> x >> y >> z;
        g[x][y]=min(g[x][y], z);
    }
    cout << dijkstra();
}

int main() {
    solve();
    return 0;
}