#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1e5 + 5,INF=0x3f3f3f3f;
int n, h[N], to[N], nex[N], w[N],idx=0,dist[N],st[N];

void add(int a, int b, int c) {
    to[idx]=b;
    nex[idx]=h[a];
    w[idx]=c;
    h[a]=idx++;
}

// spfa 最短路
// https://www.acwing.com/solution/content/105508/
/*
松弛的概念
考虑节点u以及它的邻居v，从起点跑到v有好多跑法，有的跑法经过u，有的不经过。
经过u的跑法的距离就是distu+u到v的距离。
所谓松弛操作，就是看一看distv和distu+u到v的距离哪个大一点。
如果前者大一点，就说明当前的不是最短路，就要赋值为后者，这就叫做松弛。
*/
int spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[1]=0;

    queue<int>q ;
    q.push(1);
    // 标记入队
    st[1]=1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        // 消除入队标记
        st[x]=0;

        // 遍历邻接表，计算起点经过队头到其他点距离是否变短。
        // 如果变短，该节点入队，更新其他点距离
        for (int j = h[x]; j != -1; j=nex[j]) {
            int k = to[j], p = w[j];
            // 更新距离
            if (dist[k]>dist[x]+p) {
                dist[k]=dist[x]+p;
                // 入队,
                if (!st[k])
                    q.push(k), st[k]=1;
            }
        }
    }
    return dist[n];
}
void solve()
{
    int m,x,y,z;
    cin >> n >> m;
    memset(h,-1,sizeof h);
    while (m--) {
        cin >> x >> y >> z;
        add(x,y,z);
    }
    int t = spfa();
    if (t==INF)
        puts("impossible");
    else
        cout << t;
}

int main()
{
    solve();
    return 0;
}
