#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
static const auto io_sync_off = []()
{
    // turn off sync
    ios::sync_with_stdio(false);
    // untie in/out streams
    cin.tie(nullptr);
    return nullptr;
}();
// 柱状图中最大的矩形 单调栈
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(),0);
        heights.push_back(0);
        int ans=0,n=heights.size(),cur,l;
        vector<int> s;
        for (int i = 0; i< n;i++) {
            while (!s.empty() && heights[i]<heights[s.back()]) {
                cur = s.back();
                s.pop_back();
                if (s.empty()) {
                    ans=max(ans,heights[cur]*(i-cur));
                    break;
                }
                l = s.back();
                // 加上前导 0 后导 0 eg: 0,2,1,2,0 
                // 等同于默认左端点 0, 默认右端点 n
                ans=max(ans, (i-l-1)*heights[cur]);
            }
            s.push_back(i);
        }
        return ans;
    }
};