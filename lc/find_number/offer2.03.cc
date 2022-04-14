#define FOR(i,l,r) for(int i = l; i <=r; i++)
class Solution {
public:
    // 剑指 Offer 03. 数组中重复的数字
    /**
     * 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
     * https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
     */
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        FOR(i,0,n-1) {
            while (nums[i]!=i) {
                if (nums[i]==i)
                    break;
                int idx = nums[i];
                if (nums[idx]==idx) 
                    return idx;

                nums[i]=nums[idx];
                nums[idx]=idx;
            }
        }
        return -1;
    }
};