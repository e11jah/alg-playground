#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e5+10;
int h[N],nex[N*2],to[N],in[N],vis[N],idx=0;
int q[N],n,m;
void add(int a, int b) {
    to[idx]=b;
    nex[idx]=h[a];
    h[a]=idx++;
}

void solve() {
    cin >> n>>m;
    memset(h,-1,sizeof h);
    memset(in, 0, sizeof in);
    int x,y;
    for (int i = 1; i<=m;i++) {
        cin >> x>>y,add(x,y);
        in[y]++;
    }
    queue<int> q;
    vector<int> v;
    for (int i = 1; i <= n; i++)
        if (in[i]==0)
            q.push(i);
    int u,t;
    while(!q.empty()) {
        u=q.front(),q.pop();
        if (!vis[u])
            v.push_back(u),vis[u]=1;;
        for (int j = h[u]; j!=-1;j=nex[j]) {
            t=to[j];
            in[t]--;
            if (in[t]==0)
                q.push(t);
        }
    }
    if (v.size()!=n)
        cout << -1;
    else for (int x : v)
        cout << x << ' ';
}
// 有向图 拓扑序列 拓扑排序
bool topsort() {
    // 模拟队列
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
        if (!in[i])
        // 入度为 0 入队
            q[++tt]=i;
    while (hh <= tt) {
        int u = q[hh++];
        for (int j = h[u]; j != -1; j = nex[j]) {
            int t = to[j];
            in[t]--; // 删除边
            if (in[t]==0)
                q[++tt]=t;
        }
    }
    // 判断是否 n 个点全部入队
    return tt==n-1;
}

void solve2() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    int x,y;
    for (int i = 1; i <= m; i++)
        cin >> x >> y,add(x,y),in[y]++;

    if (topsort()) {
        for (int i = 0; i < n; i++)
            cout << q[i] << ' ';
    } else 
        cout << -1;
}
int main() {
    // solve();
    solve2();
    return 0;
}