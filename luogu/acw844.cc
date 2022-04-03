#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int,int> PII;

int a[110][110],m,n,dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int d[110][110];


void solve() {
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    queue<PII> q;
    q.push(make_pair(1,1));
    memset(d, -1, sizeof(d));
    d[1][1]=0;
    PII p;
    int l,r,x,y;
    while (!q.empty()) {
        p=q.front();
        q.pop();
        x=p.first,y=p.second;

        for (int i = 0; i< 4; i++) {
            l=x+dx[i],r=y+dy[i];
            if (l < 1 || r < 1||l>n||r>m)
                continue;
            if (d[l][r]!=-1||a[l][r]==1)
                continue;
            d[l][r]=d[x][y]+1;
            q.push({l,r});
        }
    }
    cout << d[n][m];
}

int main() {
    solve();
    return 0;
}