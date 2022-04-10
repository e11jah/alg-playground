#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 200;
struct point {
    int x,y,lv;
};
typedef pair<int,int> PII;
typedef long long ll;
int n,m;
int dx[8]={-1,1,0,0,-1,-1,1,1},
    dy[8]={0,0,-1,1,-1,1,-1,1};

// 地图
int g[N][N],vis[N][N];

// 8 个方向能否看见奖杯
bool check(int a, int b, int c, int d) {
    if (a==c&&b==d)
        return true;

    for (int i = 0; i < 8; i++) {
        for (int j = 1; j ; j++) {
            int x=a+dx[i]*j,y=b+dy[i]*j;
            // cout <<"-- " << a <<' '<< b<<' ' << c<<' ' << d<<' '
            //  << x<<' ' << y<<' ' << g[x][y]<<endl;
            if (x<1||y<1||x>n||y>m||g[x][y])
                break;
            if ((x==c)&&(y==d)) {
                // cout << "r"<<endl;
                return true;
            }
        }
    }
    // cout << "-------"<<endl;
    return false;
}

void bfs(int a, int b, int c, int d) {
    queue<PII> q;
    q.emplace(a,b);
    vis[a][b]=1;
    ll lv=0, sz;
    while (!q.empty()) {
        sz=q.size();
        while (sz--) {
            PII p = q.front();
            q.pop();

            if (check(p.first,p.second, c, d)) {
                printf("%lld\n",lv);
                return;
            }
            for (int i = 0; i < 4; i++) {
                int a=p.first+dx[i],b=p.second+dy[i];
                // queue 记忆化在 push 后
                if (a>0&&a<=n&&b>0&&b<=m&&!g[a][b]&&!vis[a][b])
                    q.emplace(a,b), vis[a][b]=1;
            }
        }
        lv++;
    }
    // puts("Poor Harry");
    cout << "Poor Harry"<< endl;
}

void solve() {
    cin >> n >> m;
    string s;
    for (int i = 1; i <=n ; i++) {
        cin >> s;
        for (int j = 1; j<=m;j++)
            g[i][j]=s[j-1]=='X'?1:0;
    }

    int x1,y1,x2,y2;
    while (1) {
        cin >> x1>>y1>>x2>>y2;
        if (!x1&&!x2&&!y1&&!y2)
            break;
        memset(vis, 0, sizeof vis);
        bfs(x1,y1,x2,y2);
    }
    memset(vis, 0, sizeof vis);
    bfs(3, 4, 2, 3);
}
int main() {
    solve();
    return 0;
}