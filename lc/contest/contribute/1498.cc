
#define FOR(i,l,r) for(int i = l; i <=r; i++)
typedef long long ll;
const int N = 1e5+5,MOD=1e9+7;

class Solution {
public:
    // 巧妙的贡献计算题
    // https://leetcode-cn.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/solution/man-zu-tiao-jian-de-zi-xu-lie-shu-mu-by-leetcode-s/
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(),nums.end());
        vector<int> p(n,1);
        FOR(i,1,n-1)
            p[i]=p[i-1]*2%MOD;
        int mx,pos,ans=0,con;
        for(int i = 0; i < n && nums[i] <= target/2; i++) {
            mx=target-nums[i];
            pos=upper_bound(nums.begin(),nums.end(),mx)-nums.begin();
            con=pos>i?p[pos-i-1]:0;
            ans=(ans+con)%MOD;
        }
        return ans;
    }
};