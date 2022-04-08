#include <vector>
using namespace std;
// 四数和 套多一个 for
// 三数和 双指针
// 两数和 map 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 3)
            return ans;
        sort(nums.begin(), nums.end());
        // 最小的数字大于 0 不符合要求
        if (nums[0]>0)
            return ans;

        int k,l,r, prevL, prevR;

        for (int i = 0; i < n-2; i++) {
            k=-nums[i];
            // 跳过重复元素
            if (i > 0 && nums[i]==nums[i-1])
                continue;
            l = i+1, r = n-1;
            while (l < r) {
                if (nums[l]+nums[r]==k) {
                    prevL=nums[l], prevR=nums[r];
                    ans.push_back({nums[i], nums[l], nums[r]});
                    // 跳过重复元素避免重复解
                    while (l<r&&nums[l] == prevL)
                        l++;
                    while (l<r&&nums[r]==prevR)
                        r--;

                // 三数和大于 0 
                } else if (nums[l]+nums[r]>k)
                    r--;
                else
                    l++;
            }
        }
        return ans;
    }
};