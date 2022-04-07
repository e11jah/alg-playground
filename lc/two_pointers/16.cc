
#include <vector>

using namespace std;
// 找最接近的 数，比较差值
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans, mi=INT_MAX, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-2; i++) {
            if (i>0&&nums[i]==nums[i-1])
                continue;
            int l = i+1, r = n-1, x, t, k = target-nums[i];
            while (l < r) {
                x=nums[l]+nums[r];
                if (x == k)
                    return target;
                else if (x > k)
                    t=x-k,r--;
                else 
                    t=k-x,l++;
                if (t<mi)
                    ans = x+nums[i], mi=t;
            }
        }
        return ans;
    }
};