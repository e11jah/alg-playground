
#include <cstring>

#include <iostream>
// Bellman-Ford 有边数限制，存在负权和负权环，用 Bellman
typedef long long ll;
#define FOR(x, a, b) for (ll x = a; x <= b; x++)

using namespace std;
const int M = 1e4+5, N=505, INF=0x3f3f3f3f;
struct Edge{
    int a,b,w;
} edges[M];

int dist[N], backup[N];
//bellman-ford
// https://www.acwing.com/solution/content/6320/
void solve() {
    int n,m,k,x,y,z;
    cin >> n >> m >>k;
    memset(dist, 0x3f, sizeof dist);
    // bell-man 只存储 a,b,w
    for (int i=1; i <=m;i++) {
        cin >> x >> y >> z;
        edges[i]={x,y,z};
    }
    dist[1]=0;
    // 限制 k 次
    FOR(i,1,k) {
        memcpy(backup, dist, sizeof dist);
        // n * m
        FOR(j,1,m) {
            // 松弛操作
            int a=edges[j].a, b=edges[j].b, w=edges[j].w;
            dist[b]=min(dist[b], backup[a]+w);
        }
    }
    if (dist[n]>INF/2)
        puts("impossible");
    else
        cout << dist[n];
}

int main() {
    solve();
    return 0;
}