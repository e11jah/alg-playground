#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n,m,k,t;
const int N = 2e5+5;
int a[N][2], b[2*N], fa[2*N];

void makeSet(int sz) {
    for (int i = 1; i <=sz; i++)
        fa[i]=i;
}
int find(int x) {
    if (x!=fa[x])
        fa[x]=find(fa[x]);
    return fa[x];
}

void unionSet(int x, int y) {
    x=find(x);
    y=find(y);
    fa[x]=y;
}
int redoUnion(int t) {
    for (int i = 1; i <=m; i++) {
        if (b[a[i][0]]||b[a[i][1]])
            continue;
        if (find(a[i][0]!=find(a[i][1])))
            unionSet(a[i][0],a[i][1]),t--;
    }
    return t;
}
void solve() {
    cin >> n >>m;
    for (int i =1; i <=m; i++) {
        cin >> a[i][0]>>a[i][1];
    }
    cin >> k;
    vector<int> ans(k+1), kv(k);
    memset(b, 0, sizeof b);
    for (int i= 1; i <=k; i++) {
        cin >> t;
        b[t]=1;
    }
    int tot=redoUnion(n-k);
    int cur=k;
    // 完全破坏后
    ans[cur--]=tot;
    // 逆序重建
    while( cur>=0) {
        // 放出
        b[kv[cur]]--;
        tot =redoUnion(tot);
        ans[cur--]=tot;
    }

    for (int i = 0; i <= k; i++)
        cout << ans[i] << endl;
}

int main() {
    solve();
    return 0;
}