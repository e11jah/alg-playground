#include <iostream>
#include <vector>

using namespace std;
static const auto io_sync_off = []()
{
    // turn off sync
    ios::sync_with_stdio(false);
    // untie in/out streams
    cin.tie(nullptr);
    return nullptr;
}();
typedef long long ll;
class Solution {
public:
    // nSum 递归 求 更小的 x 数之和
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int t, k, n=nums.size();
        if (n < 4)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int pl, pr;
        for (int i = 0; i < n-3; i++) {
            // 跳过相同
            if (i > 0 && nums[i]==nums[i-1])
                continue;
            // 判断最小最大值 speed up

            // change calc order to avoid overflow
            if (nums[i]+nums[i+1]-target>-(nums[i+2]+nums[i+3])) 
                break;
            
            if (nums[i]+nums[n-1]-target<-(nums[n-2]+nums[n-3])) 
                continue;
            
            for (int j = i+1; j < n-2; j++) {
                if (j > i+1 && nums[j-1]==nums[j])
                    continue;
                // 判断最小最大值 speed up

                if (nums[i]+nums[j]-target>-(nums[j+1]+nums[j+2]))
                    break;

                if (nums[i]+nums[j]-target<-(nums[n-1]+nums[n-2]))
                    continue;
                k = target-nums[i]-nums[j];
                int l = j+1, r = n-1;
                while (l < r) {
                    if (nums[l]+nums[r]==k) {
                        pl=nums[l], pr=nums[r];
                        ans.push_back({nums[l],nums[r],nums[j],nums[i]});
                        while (l < r && nums[l]==pl) l++;
                        while (l < r && nums[r]==pr) r--;
                        // 使用 nums[l]==nums[l+1]  结束循环后要多 + 一次
                    } else if (nums[l]+nums[r]>k) {
                        r--;
                    } else l++;
                }
            }
        }
        return ans;
    }
};