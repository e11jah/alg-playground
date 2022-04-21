#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define FOR(i,l,r) for(int i = l; i <=r; i++)
typedef pair<int,int> PII;

struct edge {
    int w, now, prev;
    edge(int a, int b, int c):w(a),now(b),prev(c) {}
};

class Solution {
    int vis[110][110], n,m;
    int dx[4] = {0,0,1,-1},dy[4]={1,-1,0,0};
    
    // 并查集
    int p[101*101];
public:
    int find(int x) {
        if (x!=p[x])
            p[x]=find(p[x]);
        return p[x];
    }
    // 并查集解法
    // 建图, 边权为相邻节点的高度差, 按边权排序依次连接节点, 左右角联通时即得到最小体力消耗值
    // https://leetcode-cn.com/problems/path-with-minimum-effort/solution/duo-tu-xiang-xi-fen-xi-jie-ti-si-lu-fen-7z89x/
    int minimumEffortPath(vector<vector<int>>& heights) {
        /**
         * 一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。
         * 请你返回从左上角走到右下角的最小 体力消耗值 。
         */
        n = heights.size(), m=heights[0].size();
        FOR(i,0,n*m) p[i]=i;
        vector<edge> v;
        FOR(i,0,n-1) {
            FOR(j,0,m-1) {
                // 行 * 列
                int now = i*m+j;
                if (i)
                    // 上一行
                    v.emplace_back(abs(heights[i][j]-heights[i-1][j]), now, now-m);
                if (j)
                    // 上一列
                    v.emplace_back(abs(heights[i][j]-heights[i][j-1]), now, now-1);
            }
        }
        sort(v.begin(), v.end(), [](const edge l, const edge r) {
            return l.w<r.w;
        });

        for(const edge e : v) {
            // 联通节点
            p[find(e.now)]=find(e.prev);
            // 注意右下角的点坐标计算
            if (find(0)==find((n-1)*m+(m-1)))
                return e.w;
        }
        return 0;
    }

    // 二分 + bfs
    // 时间复杂度 O(logC) * O(mn) C 为高度范围
    int solve(vector<vector<int>>& heights) {
        // 二分搜索高度差
        n = heights.size(), m=heights[0].size();
        queue<PII> q;
        PII p;
        int l = 0, r = 1e6, mid,ans=-1;
        int x,y,nx,ny;
        while (l<=r)  {
            mid=(l+r)/2;
            // bfs/dfs 找满足高度差的路径
            memset(vis, 0, sizeof vis);
            q.emplace(0,0),vis[0][0]++;
            while (!q.empty()) {
                p=q.front();
                q.pop();

                FOR(i,0,3) {
                    x=p.first,y=p.second;
                    nx=x+dx[i],ny=y+dy[i];
                    if (nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny]&&abs(heights[x][y]-heights[nx][ny])<=mid) 
                        q.emplace(nx,ny),vis[nx][ny]++;
                }
            }
            if (vis[n-1][m-1])
                ans=mid,r=mid-1;
            else
                l=mid+1;
        }

        return ans;
    }
};