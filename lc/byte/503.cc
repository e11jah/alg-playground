#include <vector>
using namespace std;
// 下一个更大元素 断环成链 单调栈
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            nums.push_back(nums[i]);

        vector<int> ans(n*2,-1), s;
        for (int i = 0; i <2*n-1; i++) {
            while (!s.empty() && nums[i] > nums[s.back()]) {
                ans[s.back()]=nums[i];
                s.pop_back();
            }
            s.push_back(i);
        }
        ans.resize(n);
        return ans;
    }
};