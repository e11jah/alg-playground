#include <vector>
using namespace std;
#define FOR(i,l,r) for(int i = l; i <=r; i++)
class Solution {
public:

    int missingNumber(vector<int>& nums) {
        int n = nums.size(),ans=n;
        FOR(i,0,n-1) {
            // 异或两次抵消
            ans^=nums[i];
            // 异或一次保留
            ans^=i;
        }
        // 剩下的就是没出现的数
        return ans;
    }
    int solve1(vector<int> &nums) {
        // 原地哈希 2*O(n)
        // 丢失的数字 同 lc 41 双倍经验
        int n = nums.size();
        nums.push_back(-1);

        FOR(i,0,n) {
            while (nums[i]!=i) {
                if (nums[i]<0||nums[i]>n||nums[i]==i)
                    break;
                int idx = nums[i];
                nums[i]=nums[idx];
                nums[idx]=idx;
            }
        }
        FOR(i,0,n)
            if(nums[i]!=i)
                return i;
        return n+1;
    }
};