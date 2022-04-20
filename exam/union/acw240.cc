#include <iostream>

using namespace std;

const int N = 5e4+5;

// 并查集 维护节点到根节点的距离
int p[N], d[N];

int find(int x) {
    if (x!=p[x]) {
        int t = find(p[x]);
        // 压缩路径并累加父节点到根节点距离
        d[x]+=d[p[x]];
        p[x]=t;
    }
    return p[x];
}
/**
 * 食物链构成环形
 */
void solve() {
    int n,k;
    cin>>n>>k;
    for (int i = 1; i <= n; i++)
        p[i]=i, d[i]=0;

    int op,x,y,px,py,ans=0;
    while (k--) {
        cin >> op >> x >> y;
        if (x>n||y>n) 
            ans++;
        else {
            px=find(x),py=find(y);
            if (op==1) {
                // 同类，在一个集合中，在食物链上的位置应该一样（距根距离差值 MOD 3 == 0）
                if (px==py && (d[x]-d[y])%3)//!=0省略
                    ans++;
                else if (px!=py){
                    // 定义 d[px] = (d[x]+?-d[y])%3==0
                    p[px]=py;
                    d[px]=d[y]-d[x]; 
                }
            } else {
                if (x==y) ans++;
                // 在一个集合中，两者在食物链上的位置差不能超过 1
                else if (px==py&&((d[x]-d[y]-1)%3))
                    ans++;
                // d[px]=(d[x]+?-d[y]-1)%3==0
                else if (px!=py) {
                    p[px]=py;
                    d[px]=d[y]+1-d[x];
                }
            }
        }
    }
    cout<<ans;
}

int main() {
    solve();
    return 0;
}