#include <vector>
#include <tuple>
#include <queue>
using namespace std;


class Solution {
    int vis[13];
public:
    // 访问所有节点的最短路径
    // 状态压缩 + bfs 
    int shortestPathLength(vector<vector<int>>& graph) {

        // 使用 bfs 保证最短
        
        // 记录 (u,mask), 防止无效搜索
        // 对 (u,mask,dist) 进行 bfs
        int n = graph.size();

        queue<tuple<int,int,int>> q;

        vector<vector<int>> vis(n, vector<int>(1<<n));

        for (int i = 0; i < n; i++) {
            q.emplace(i, 1<<i, 0);
            vis[i][1<<i]=1;
        }
        int ans=0;
        while (!q.empty()) {
            auto [u,mask, d] = q.front();
            q.pop();

            if (mask==(1<<n)-1) {
                ans=d;
                break;
            }
            // 遍历邻接点
            for (int child : graph[u]) {
                int childMask = mask|(1<<child);
                if (!vis[child][childMask]) {
                    // u 表示当前位于的节点编号
                    // mask 表示节点是否经过
                    q.emplace(child, childMask, d+1);
                    vis[child][childMask]=1;
                }
            }
        }
        return ans;
    }
};