#include <vector>
using namespace std;
class Solution {
public:
    /**
     * 
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    int minPathSum(vector<vector<int> >& matrix) {
        // write code here
        int n = matrix.size(),m=matrix[0].size();
        // f[n][m]=min(f[i-1][j],f[i][j-1])
        vector<vector<int>> f(n, vector<int>(m,0));
        for (int i = 0;i<n;i++) {
            f[i][0]=matrix[i][0];
            if (i>0)
                f[i][0]+=f[i-1][0];
        }
        for (int j =0;j<m;j++) {
            f[0][j]=matrix[0][j];
            if (j>0)
                f[0][j]+=f[0][j-1];
        }
        
        for (int i = 1; i<n;i++)
            for (int j = 1; j<m;j++)
                f[i][j]=matrix[i][j]+min(f[i-1][j],f[i][j-1]);
        
        return f[n-1][m-1];
    }
};