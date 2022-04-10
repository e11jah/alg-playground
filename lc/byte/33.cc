#include <vector>

using namespace std;
class Solution {
public:
    // 搜索两段升序数组 二分
    int search(vector<int>& nums, int target) {
        int n = nums.size(),l,r,m;
        if (nums[0]>target&&nums[n-1]<target)
            return -1;
        if (nums[0]==target)
            return 0;
        if (nums[n-1]==target)
            return n-1;
        l=0,r=n-1;
        if (nums[0]<target) {
            // 升序搜索
            while (l<=r&&nums[r]<target) {
                r--;
            }

        } else if (nums[n-1]>target) {
            // 降序搜索
            while (l<=r&&nums[l]>target)
                l++;
        }
        while (l<=r) {
            m=(l+r)/2;
            if (nums[m]==target)
                return m;
            
            if (nums[m]<target)
                l=m+1;
            else r=m-1;
        }
        return -1;
    }
};