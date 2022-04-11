#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1005;
string g[N];
int n,m, dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};
typedef pair<int,int> PII;
typedef long long ll;

struct node {
    int x,y,s;
    node(int a, int b, int c): x(a),y(b),s(c) {}
};

int bfs(int x, int y) {
    queue<node> q;
    q.emplace(x,y,0);
    int nx,ny;
    while (!q.empty()) {
        node h = q.front();
        q.pop();
        if (h.s>0&&h.x==x&&h.y==y) {
            return h.s;
        }
        for (int i=0;i < 4; i++) {
            nx=h.x+dx[i], ny=h.y+dy[i];
            if (nx<0||nx>=n||ny<0||ny>=m)
                continue;
            if ((g[h.x][h.y]=='0'&&g[nx][ny]=='1')
                ||(g[h.x][h.y]=='1'&&g[nx][ny]=='0'))
                q.emplace(nx,ny,h.s+1);
        }
        
    }
    return -1;
}

void solve() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    int x,y;
    for (int i = 0; i < m; i++) {
        cin>>x>>y;
        cout << bfs(x-1,y-1);
    }
}

int main() {
    solve();
    return 0;
}