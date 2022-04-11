
#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
/**
重走迷宫
. 空地 # 石块
从 S 出发, F 离开, 离开之前碰石头

3 5 3
#....
####.
FS...
1 1
2 3
2 3 
 */
int n,m,k;
string g[105];
struct node {
    int x,y,step,;
};
int bfs(int a, int b) {
    queue<
}
void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >>g[i];
}

int main() {
    solve();
    return 0;
}
