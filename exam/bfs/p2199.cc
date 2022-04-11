#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 200;
struct node {
    int x,y,lv;
    node(int a, int b, int c):x(a),y(b),lv(c) {}
};
typedef pair<int,int> PII;
typedef long long ll;
int n,m;
int dx[8]={-1,1,0,0,-1,-1,1,1},
    dy[8]={0,0,-1,1,-1,1,-1,1};

// 地图
string g[200];
int vis[N][N];

// 8 个方向能否看见奖杯
bool check(int a, int b, int c, int d) {
    if (a==c&&b==d)
        return true;

    for (int i = 0; i < 8; i++) {
        for (int j = 1; j ; j++) {
            int x=a+dx[i]*j,y=b+dy[i]*j;
            if (x<0||y<0||x>=n||y>=m||g[x][y]=='X')
                break;
            if (x==c&&y==d) {
                return true;
            }
        }
    }
    return false;
}

void bfs(int a, int b, int c, int d) {
    queue<node> q;
    q.emplace(a,b, 0);
    vis[a][b]++;
    while (!q.empty()) {

        node p = q.front();
        q.pop();

        if (check(p.x,p.y, c, d)) {
            cout <<p.lv<<endl;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int a=p.x+dx[i],b=p.y+dy[i];
            // queue 记忆化在 push 后
            if (a>=0&&a<n&&b>=0&&b<m&&g[a][b]=='O'&&!vis[a][b])
                q.emplace(a,b, p.lv+1), vis[a][b]++;
        }

    }
    cout << "Poor Harry" << endl;
}

void solve() {
    cin >> n >> m;

    for (int i = 0; i <n ; i++) 
        cin >> g[i];

    int x1,y1,x2,y2;
    while (1) {
        cin >> x1>>y1>>x2>>y2;
        if (!x1&&!x2&&!y1&&!y2)
            break;
        memset(vis, 0, sizeof vis);
        bfs(x1-1,y1-1,x2-1,y2-1);
    }
}

int main() {
    solve();
    return 0;
}