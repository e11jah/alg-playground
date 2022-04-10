#include <vector>

#include <map>

using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0]=1;
        int l = 0,s=0,r,ans=0;
        for (r=0; r < nums.size(); r++) {
            // pre[i]=pre[i-1]+nums[i]
            s+=nums[r];
            // if pre[i]-pre[j-1]==k then pre[i]-k==pre[j-1]
            if (mp.count(s-k))
                ans+=mp[s-k];
            // 统计 pre[j-1] 数量
            mp[s]++;
        }
        return ans;
    }
};