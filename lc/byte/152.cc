#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 维护最大最小值相互转移
        int ma=nums[0],mi=nums[0],ans=nums[0], t;
        for (int i = 1; i < nums.size(); i++) {
            t=ma;
            ma=max(ma*nums[i], max(nums[i], nums[i]*mi));
            mi=min(mi*nums[i], min(nums[i], nums[i]*t));
            ans=max(ma,ans);
        }

        return ans;
    }
};