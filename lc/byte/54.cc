#include <vector>

using namespace std;
// 模拟
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int n = matrix.size(), m = matrix[0].size();
        int op=0, t=0,  x=0, y=0;
        ans.push_back(matrix[0][0]);
        while (ans.size() < n*m) {
            while (op==0&&y+1<m-t)
                ans.push_back(matrix[x][++y]);

            while (op==1&&x+1<n-t)
                ans.push_back(matrix[++x][y]);

            while (op==2&&y-1>=t)
                ans.push_back(matrix[x][--y]);

            while (op==3&&x-1>t)
                ans.push_back(matrix[--x][y]);

            op=++op%4;
            if (op==0)
                t++;
        }
        return ans;
    }
};