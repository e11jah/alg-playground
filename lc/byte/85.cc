#include <vector>
using namespace std;
// 套皮版 84 柱状图中最大的矩形 单调栈
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size(), c = matrix[0].size(),ans=0;
        vector<int> heights(c+2),s;
        for (int i = 0; i < r; i++) {
            s.clear();
            for (int j = 1; j <= c; j++) {
                // 当前行 = 0 之前的高度清零
                heights[j]=matrix[i][j-1]=='0'?0:heights[j]+1;
            }
            ans = max(ans, maxArea(heights,s));
        }
        return ans;
    }
    // 相邻柱状图的最大面积
    int maxArea(vector<int> & h, vector<int> & s) {
        int ans = 0;
        for (int i = 0; i < h.size(); i++) {
            while (!s.empty() && h[i]<h[s.back()]) {
                int cur = s.back();
                s.pop_back();

                ans=max(ans,(i-s.back()-1)*h[cur]);
            }
            s.push_back(i);
        }
        return ans;
    }
};