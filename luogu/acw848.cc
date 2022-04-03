#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e5+10;
int h[N],nex[N*2],to[N],in[N],vis[N],idx=0;

void add(int a, int b) {
    to[idx]=b;
    nex[idx]=h[a];
    h[a]=idx++;
}
void rm(int a, int b) {

}

void solve() {
    int n,m;
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

int main() {
    solve();
    return 0;
}