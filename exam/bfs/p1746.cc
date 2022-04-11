#include <iostream>
#include <queue>
using namespace std;

const int N = 1e3+5;
int n;
int g[N][N],vis[N][N];
int dx[4]={0,0,1,-1},
    dy[4]={1,-1,0,0};
typedef pair<int,int> PII;
int bfs(int a, int b, int c, int d) {
    queue<PII> q;
    q.emplace(a,b);
    PII p;
    int dis=0,sz,x,y;
    while (!q.empty()) {
        sz=q.size();
        while (sz--) {
            p=q.front();
            q.pop();
            if (p.first==c&&p.second==d)
                return dis;
            // cout << p.first << ' '<<p.second<<' '<<c<<' '<<d<< endl;
            for (int i =0; i < 4; i++) {
                x=p.first+dx[i],y=p.second+dy[i];
                if (x >0 && x<=n&&y>0&&y<=n&&!g[x][y]&&!vis[x][y])
                    q.emplace(x,y), vis[x][y]++;
            }
        }
        dis++;
    }
    return -1;
}

void solve() {
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++) {
        cin>>s;
        for (int j = 1; j <= n; j++) {
            g[i][j]=s[j-1]=='1'?1:0;
        }
    }
    int x1,y1,x2,y2;
    cin >> x1>>y1>>x2>>y2;

    cout << bfs(x1,y1,x2,y2);
}

int main() {
    solve();
    return 0;
}