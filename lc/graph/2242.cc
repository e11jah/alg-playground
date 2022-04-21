typedef pair<int,int> PII;
#define FOR(i,l,r) for(int i = l; i <=r; i++)

class Solution {
public:
    // 解法 枚举边
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<vector<PII>> children(n);
        for(vector<int> e : edges) {
            // 存储负数方便 nth_element 排序
            children[e[0]].emplace_back(-scores[e[1]], e[1]);
            children[e[1]].emplace_back(-scores[e[0]], e[0]);
        }

        // 排序, 需要的是每个节点相邻三个最大分数的节点
        FOR(i,0,n-1) {
            if (children[i].size()>3) {
                // 第三个元素之后的元素都比第三个元素大
                nth_element(children[i].begin(), children[i].begin()+3, children[i].end());
                // 存负数保证后面的分数都比前面小, 实际前三个是最大分数（无序）
                children[i].resize(3);
            }
        }
        int x,y,a,b,ans=-1;
        // 四个节点三条边
        // 枚举中间边
        for (vector<int> e : edges) {
            x=e[0], y=e[1];
            for (auto [pa, a]: children[x]) {
                for (auto [pb, b] : children[y]) {
                    // 没有重边自环
                    if (a!=b&&b!=x&&a!=y) {

                        ans=max(ans, scores[x]+scores[y]-pb-pa);
                    }
                }
            }
        }

        return ans;
    }
};