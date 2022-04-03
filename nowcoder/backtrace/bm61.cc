#include <vector>

using namespace std;
class Solution {
    int m,n,dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
//     vector<vector<int>> vis;
public:
    int dfs(vector<vector<int> >& matrix, vector<vector<int>>& vis, int a, int b) {
        if (vis[a][b])
            return vis[a][b];
        int x,y,ret=0,t;
        for (int i =0; i< 4;i++) {
            x=a+dx[i],y=b+dy[i];
            if (x<0||y<0||x>=n||y>=m)
                continue;
            if (matrix[x][y]<=matrix[a][b])
                continue;
            t=dfs(matrix, vis,x,y);
            ret=t>ret?t:ret;
        }
        vis[a][b]=1+ret;
        return 1+ret;
    }
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 递增路径的最大长度
     * @param matrix int整型vector<vector<>> 描述矩阵的每个数
     * @return int整型
     */
    int solve(vector<vector<int> >& matrix) {
        // write code here
        n=matrix.size();
        if (n<1)
            return 0;
        m=matrix[0].size();
        
//         vis.resize(n, vector<int>(m,0));
        // reduce mem size
        vector<vector<int>> vis(n, vector<int>(m,0));
        int ans=0,t;
        for (int i =0;i<n;i++)
            for (int j=0;j<m;j++) {
                t=dfs(matrix,vis,i,j);
                ans=t>ans?t:ans;
            }
                
        return ans;
    }
};