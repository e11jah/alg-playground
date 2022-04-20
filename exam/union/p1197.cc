#include <iostream>
#include <vector>
#include <cstring>
#define RI2(x, y) scanf("%d%d", &x, &y)
#define RI(x) scanf("%d", &x)
#define PLN(x) printf("%d\n", x)
using namespace std;
int n,m,k,t;
const int N = 2e5+5;
int b[2*N], fa[2*N];

// #9 tle 预警：题目给的数据范围是 1≤n≤2m，而m是边数，因此n最大可以到400000
int h[N*2], to[N*4], nex[N*4], idx=0;

inline void add(int a, int b) {
    to[idx]=b, nex[idx]=h[a], h[a]=idx++;
}

inline void makeSet(int sz) {
    for (int i = 1; i <=sz; i++)
        fa[i]=i;
}
inline int find(int x) {
    if (x!=fa[x])
        fa[x]=find(fa[x]);
    return fa[x];
}

void solve() {
    ios::sync_with_stdio(false);

    memset(h, -1, sizeof h);

    RI2(n,m);
    int x,y;
    for (int i =1; i <=m; i++) {
        RI2(x,y);
        add(x,y),add(y,x);
    }
    RI(k);
    vector<int> ans(k+1), kv(k);
    memset(b, 0, sizeof b);
    for (int i= 0; i <k; i++) {
        RI(kv[i]);
        b[kv[i]]=1;
    }
    makeSet(n);
    int c = n-k;
    // 毁灭所有星球后的联通块数量
    // 邻接表 id 遍历
    for (int i= 1; i <idx; i+=2) {
        // ^1 =i-1, 由于双向, 可遍历 src & dst
        if (!b[to[i^1]]&&!b[to[i]]) {
            x=find(to[i^1]),y=find(to[i]);
            if (x!=y)
                fa[x]=y,c--;
        }
    }
    ans[k]=c;

    // 逆序重建
    for (int i = k-1; i >=0; i--) {
        // 放出
        b[kv[i]]--;
        // 添加一个连通块
        c++;
        for (int e = h[kv[i]]; e != -1; e = nex[e]) {
            if (!b[to[e]]) {
                x=find(kv[i]),y=find(to[e]);
                // cout << "g "<<kv[i]<<' '<<to[e]<< ' '<<x<<' '<<y<<endl;
                if (x!=y)
                    fa[x]=y,c--;
            }
        }
        ans[i]=c;
    }

    for (int i = 0; i <= k; i++)
        PLN(ans[i]);
}

int main() {
    solve();
    return 0;
}