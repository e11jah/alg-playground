#define FOR(i,l,r) for(int i = l; i <=r; i++)
const int N = 1e5+5;
class Solution {
    int ans=0;
    vector<int> children[N];
public:
    // 找出图的路径上任意一对相邻节点都没有分配到相同字符的 
    // 最长路径 ，并返回该路径的长度。
    // https://leetcode-cn.com/problems/longest-path-with-different-adjacent-characters/solution/c-by-answerer-l3ec/
    int dfs(int nod, const string & s) {
        // 维护路径最长的两个子路径
        int m1=0,m2=0;
        for(int child : children[nod]) {
            // 即使相邻字符相同也要搜索子树更新答案
            int t = dfs(child,s);
            if (s[nod]!=s[child]) {
                if (t>m1)
                    swap(m1,m2),m1=t;
                else if (t>m2)
                    m2=t;
            } 
        }
        // 答案可以为两个子路径加根节点的路径和
        ans=max(ans,m1+m2+1);
        // 返回最长路径
        return m1+1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        
        FOR(i,1,n-1) {
            children[parent[i]].push_back(i);
        }
        dfs(0, s);
        return ans;
    }
};