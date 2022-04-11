#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 2e5+5;
typedef pair<int,int> PII;
int n,m;

int b[N], p[N], v[N];

// 使用邻接表存储稀疏图
int h[N],to[N*2],nex[N*2],idx=0;

void add(int a, int b) {
    to[idx]=b, nex[idx]=h[a];
    h[a]=idx++;
}

int find(int x) {
    if (x != p[x])
        p[x]=find(p[x]);
    return p[x];
}
// p3144 数据加强版
void solve() {
    cin >> n >> m;
    memset(b, 0, sizeof b);
    memset(h, -1, sizeof h);
    int x,y,k=0;
    for (int i = 0; i <m;i++) {
        cin>>x>>y;
        // 双向
        add(x,y),add(y,x);
    }
    for (int i = 1; i <= n; i++)
        cin>>v[i],b[v[i]]=1,p[i]=i;

    vector<int> ans(n,0);
    b[v[n]]--;
    ans[n-1]=1;
    for (int j = n-1; j >0;j--) {
        // 放出
        b[v[j]]--;

        // 遍历邻接表
        for (int d = h[v[j]]; d != -1; d=nex[d]) {
            if (!b[to[d]]) {
                x=find(v[j]),y=find(to[d]);
                if (x!=y)
                    k++,p[x]=y;
            }
        }

        // 合并次数=开放节点数 -1 则全联通
        if (k==n-j) ans[j-1]=1;
            
    }
    for (int i = 0; i < n; i++) {
        if (ans[i]==1)
            cout << "YES"<<endl;
        else
            cout << "NO"<<endl;
    }
}

int main() {
    solve();
    return 0;
}