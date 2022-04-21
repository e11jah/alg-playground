#define FOR(i,l,r) for(int i = l; i <=r; i++)
const int N = 31;
class Solution {
    int p[N];
public:
    int find(int x) {
        if (x!=p[x])
            p[x]=find(p[x]);
        return p[x];
    }
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() /2;
        FOR(i,1,n)
            p[i]=i;
        // 题意中相邻两个座位为一组, 跨座位相邻仍不满足坐在一起, 如 0,2,3,1 中 2,3 不满足要求
        for (int i = 0; i < 2*n; i+=2) {
            // 连通
            p[find(row[i]/2+1)]=p[find(row[i+1]/2+1)];
        }
        int ans=0;
        FOR(i,1,n)
            if (find(i)==i)
                ans++;
        // 多个分组在一个集合内才需要交换
        // 交换次数为块中节点数 -1
        return n-ans;
    }
};