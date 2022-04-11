#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 3e3+5;
typedef pair<int,int> PII;
int n,m;
PII a[N];
int b[N], p[N], v[N];

int find(int x) {
    if (x != p[x])
        p[x]=find(p[x]);
    return p[x];
}
// 并查集
void solve() {
    cin >> n >> m;
    memset(b, 0, sizeof b);
    for (int i = 0; i <m;i++)
        cin>>a[i].first>>a[i].second;
    for (int i = 0; i < n; i++)
        cin>>v[i],b[v[i]]=1,p[i+1]=i+1;

    vector<int> ans(n,0);
    int x,y;
    for (int j = n-1; j >=0;j--) {
        // 放出
        b[v[j]]=0;
        for (int i = 0; i < m; i++) {
            x=a[i].first,y=a[i].second;
            if (!b[x]&&!b[y])
                p[find(x)]=find(y);
        }

        // 连通块数量==根数量
        for (int i =1;i<=n;i++) 
            if (!b[i]&&find(i)==i) 
                ans[j]++;
            
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