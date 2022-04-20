#include <iostream>
#include <string>
using namespace std;

const int N = 1e5+5;
int p[N],sz[N];

int find(int x) {
    if (x!=p[x])
        p[x]=find(p[x]);
    return p[x];
}
// 并查集维护连通块节点数量
void solve() {
    int n,m;
    cin >> n >> m;
    string op;
    
    for (int i = 1; i <= n ; i++)
        p[i]=i,sz[i]=1;
    int a,b,pa,pb;
    while (m--) {
        cin >> op;
        if (op=="C") {
            cin >> a >> b;
            pa=find(a),pb=find(b);
            if (pa!=pb)
                // 父节点 size += 子节点 size
                sz[pb]+=sz[pa],p[pa]=pb;
        }
        if (op=="Q1") {
            cin >> a >> b;
            if (find(a)==find(b))
                cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        if (op=="Q2") {
            cin >>a;
            cout << sz[find(a)] << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}