#include <vector>
#include <stack>
using namespace std;
// 接雨水 单调栈
class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0,n=height.size();
        // s 从栈顶到栈底单调升
        stack<int> s;
        for (int i = n-1; i >=0; i--) {
            while (!s.empty() && height[s.top()] < height[i]) {
                int cur = s.top();
                s.pop();
                if (s.empty())
                    break;
                
                int r = s.top();
                // 只算中间区域, 多-1
                int w = r - i-1;
                int h = min(height[r],height[i])-height[cur];
                ans+=w*h;
            }
            s.push(i);
        }
        return ans;
    }
};