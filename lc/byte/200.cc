#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> PII;
class Solution {
    int vis[301][301]={0};
    int dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};
public:
    void bfs(vector<vector<char>> & grid, int x, int y, int m, int n) {
        queue<PII> q;
        q.emplace(x,y);
        vis[x][y]=1;
        int a,b;
        while (!q.empty()) {
            auto [x,y]=q.front();
            q.pop();
            for (int i=0;i<4;i++) {
                a=x+dx[i],b=y+dy[i];
                if (a>=0&&a<m&&b>=0&&b<n&&!vis[a][b]&&grid[a][b]=='1') 
                    // 先标记避免重复入队
                    q.emplace(a,b), vis[a][b]=1;
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0, m = grid.size(), n= grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                if (!vis[i][j]&&grid[i][j]=='1')
                    bfs(grid, i, j, m, n), ans++;
        }
        return ans;
    }
};