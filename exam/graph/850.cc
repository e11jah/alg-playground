#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

const int N = 1e6+10, INF=0x3f3f3f3f;
//稀疏图 邻接表
int n, h[N],to[N],nex[N],w[N],idx=0, dist[N],st[N];
typedef pair<int,int> PII;
// 通过小根堆优化重边，最终计算最短边权
void add(int a, int b, int x) {
    to[idx]=b;
    nex[idx]=h[a];
    w[idx]=x;
    h[a]=idx++;
}

// dijkstra 邻接表 堆优化 
int dijkstra() {
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    dist[1]=0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    // 默认 first 排序, 为距离, second 节点
    // 最小堆维护距源距离最短的点
    heap.emplace(0, 1);
    while (!heap.empty()) {
        int d, nod;
        // 取不在集合 S 中的最小的点
        tie(d,nod) = heap.top();
        heap.pop();
        // 找到 n 最短路
        if (nod==n)
            break;

        if (st[nod])
            continue;
        st[nod]=1;

        // 用堆中维护的最小距离中转点更新其他点距离
        for (int j = h[nod]; j!=-1; j = nex[j]) {
            int t = to[j];
            if (!st[t]&&dist[t]>d+w[j]) {
                dist[t]=d+w[j];
                heap.emplace(dist[t], t);
            }
        }
    }

    return dist[n]!=INF?dist[n]:-1;
}

void solve() {
    int m,x,y,z;
    cin >> n >> m;

    memset(h, -1, sizeof h);

    while (m--) {
        cin >> x >> y >> z;
        add(x,y,z);
    }
    cout << dijkstra();
}
int main() {
    solve();
    return 0;
}
