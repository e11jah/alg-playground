#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
/**
 * 链接：https://www.nowcoder.com/questionTerminal/e3fc4f8094964a589735d640424b6a47
    来源：牛客网

    假设一个探险家被困在了地底的迷宫之中，要从当前位置开始找到一条通往迷宫出口的路径。
    迷宫可以用一个二维矩阵组成，有的部分是墙，有的部分是路。
    迷宫之中有的路上还有门，每扇门都在迷宫的某个地方有与之匹配的钥匙，只有先拿到钥匙才能打开门。
    请设计一个算法，帮助探险家找到脱困的最短路径。如前所述，迷宫是通过一个二维矩阵表示的，
    每个元素的值的含义如下 0-墙，1-路，2-探险家的起始位置，3-迷宫的出口，大写字母-门，
    小写字母-对应大写字母所代表的门的钥匙
 * 
 */
const int N = 105;
string g[110];

int n, m;
// 最多 10 扇门 2^10
// 压缩钥匙状态，记录带钥匙的访问状态
int vis[N][N][1100];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};

struct node {
    int x, y, key, step;
    node(){}
    node(int a, int b, int c, int d):x(a),y(b),key(c),step(d) {}
};

bool check(char c, int lower) {
    if (lower&&c>='a'&&c<='z')
        return true;
    if (!lower && c>='A'&&c<='Z')
        return true;
    return false;
}

int bfs(int x, int y) {
    queue<node> q;

    q.emplace(x,y,0,0);
    vis[x][y][0]++;
    int nx,ny, nk;
    while (!q.empty()) {
        node e = q.front();
        q.pop();
        
        // bfs 返回的时候必定最短路
        if (g[e.x][e.y]=='3') {
            return e.step;
        }
        for (int i = 0; i < 4; i++) {
            nx=e.x+dx[i],ny=e.y+dy[i];
            if (nx<0||nx>=n||ny<0||ny>=m||g[nx][ny]=='0')
                continue;
            int nk=e.key;       
            // 捡钥匙
            if (check(g[nx][ny], 1))
                nk|=1<<(g[nx][ny]-'a');
            // 没有钥匙不能通行
            if (check(g[nx][ny], 0)&&((nk>>(g[nx][ny]-'A'))&1)==0) {
                    continue;
            }
            if (vis[nx][ny][nk]) continue;

            q.emplace(nx,ny,nk,e.step+1);
            vis[nx][ny][nk]++;
        }
    }
    return -1;
}

void solve() {
    cin >> n >> m;
    int sx,sy;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    memset(vis, 0, sizeof vis);
    int ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j]=='2')
                ans = bfs(i,j);
        }
    }
    cout << ans << endl;

}

int main() {
    solve();
    return 0;
}