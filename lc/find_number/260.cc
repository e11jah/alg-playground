#include <vector>
using namespace std;
#define FOR(i,l,r) for(int i = l; i <=r; i++)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size(), x=nums[0],s1=0,s2=0,k;

        FOR(i,1,n-1) 
            x^=nums[i];
        for(int i = 31; i>0;i--) {
            if ((x>>i)&1) {
                // 找到为1的最低位
                k=i;
            }
        }

        // 分组, 分为与异或和 x 的 k 位 1 相同与不同的两个组
        FOR(i,0,n-1) {
            if ((nums[i]>>k)&1) {
                s1^=nums[i];
            } else {
                s2^=nums[i];
            }
        }
        ans.push_back(s1);
        ans.push_back(s2);
        return ans;
    }
};