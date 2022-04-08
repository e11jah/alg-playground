#include <vector>
#include <algorithm>
using namespace std;
// 最小高度树 bfs + 拓扑排序
typedef pair<int,int> PII;
class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};
        if (n==2)
            return edges[0];

        // 邻接表爆空间，换 vec
        vector<vector<int>> children(n);
        vector<int> d(n,0);
        for (vector<int> e : edges) {
            children[e[0]].push_back(e[1]);
            children[e[1]].push_back(e[0]);
            // 计算度
            d[e[0]]++;
            d[e[1]]++;
        }
        vector<int> ans;
        vector<PII> q(n);
        int h=0,t=0;
        for (int i = 0; i < n; i++) {
            // 叶子入队
            if (d[i] == 1)
                q[t].first=i,q[t++].second=1;
        }
        int m=0,nod,height,x;
        while (h!=t) {
            nod = q[h].first;
            height=q[h++].second;

            // 记录最大层数
            m=m>height?m:height;
            // 减去度数, 重新找叶子
            d[nod]--;
            // 遍历邻接点
            for (int x : children[nod]) {
                // 无向图,双向减
                d[x]--;
                if (d[x]==1)
                    q[t].first=x,q[t++].second=height+1;
            }
        }
        for (int i = t-1; i >= 0; i--) {
            if (q[i].second!=m)
                break;
            ans.push_back(q[i].first);
        }

        return ans;
    }
};