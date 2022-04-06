#include <vector>
using namespace std;

// 最大子数组和
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), s,m=s=nums[0];
        for (int i = 1; i < n; i++) {
            if (s>0)
                s+=nums[i];
            else
                s=nums[i];
            m=max(m,s);
        }
        return m;
    }
};