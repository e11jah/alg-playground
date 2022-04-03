#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n,m;
const int N = 1e5+10;
int h[N],dis[N],to[N],nex[2*N],idx=0;

void add(int a, int b) {
    to[idx]=b;
    nex[idx]=h[a];
    h[a]=idx++;
}

void solve() {
    memset(h, -1, sizeof(h));

    memset(dis, -1, sizeof(dis));
    cin >> n>>m;
    int x,y;
    for (int i = 1; i<=m; i++) {
        cin>>x>>y;
        add(x,y);
    }
    queue<int> q;
    q.push(1),dis[1]=0;
    int u,t;
    while (!q.empty()) {
        u=q.front(),q.pop();
        for (int j = h[u];j!=-1;j=nex[j]) {
            t=to[j];
            if (dis[t]==-1) {
                q.push(t);
                dis[t]=dis[u]+1;
            }
        }
    }
    cout << dis[n];
}

int main() {
    solve();
    return 0;
}