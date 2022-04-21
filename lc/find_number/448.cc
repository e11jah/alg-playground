#include <vector>
using namespace std;

#define FOR(i,l,r) for(int i = l; i <=r; i++)
class Solution {
public:
    // 找到所有数组中消失的数字 原地哈希
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        FOR(i,0,n-1) {
            while (nums[i]!=i+1) {
                if (nums[i]<1||nums[i]>n||nums[i]==i+1)
                    break;
                int idx = nums[i]-1;
                if (nums[idx]==idx+1)
                    break;
                nums[i]=nums[idx];
                nums[idx]=idx+1;
            }
        }
        FOR(i,0,n-1) {
            if (nums[i]!=i+1)
                ans.push_back(i+1);
        }
        return ans;
    }
};