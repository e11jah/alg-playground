class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 1~31 个 bit 位计数, 不为 3 的倍数即答案
        int k = 3,ans=0;
        for (int i = 31; i>=0; i--) {
            int c  = 0, mask=1<<i;
            for (int x : nums) {
                if (x & mask)
                    c++;
            }
            if (c%k!=0)
                ans|=mask;
        }
        return ans;
    }
};