#include <vector>

using namespace std;
// 有效三角形个数
// 排序 + 双端双指针
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(),k,ans=0;
        // 逆序 枚举前面的较小的数字看是否大于第三边
        for (int i = n-1; i > 1; i--) {
            int l = 0, r = i-1;
            while (l < r) {
                if (nums[l]+nums[r]>nums[i]) {
                    // 如果 nums[l] + nums[r] > nums[i]，同时说明 nums[l + 1] + nums[r] > nums[i], ..., nums[r - 1] + nums[r] > nums[i]，满足的条件的有 r - l 种，r 左移进入下一轮。
                    ans+=r-l;
                    r--;
                } else 
                    l++;
            }
           
        }
        return ans;
    }
};