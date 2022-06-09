#define FOR(i,l,r) for(int i = l; i <=r; i++)
typedef long long ll;

class Solution {
public:
    // 双倍经验 907
    // 单调栈解法 O(n)
    // https://leetcode-cn.com/problems/sum-of-subarray-ranges/solution/daydayuppp-dan-diao-zhan-on-zuo-fa-by-da-pmmt/
    long long subArrayRanges(vector<int>& nums) {
        ll ans=0;
        vector<int> stk(1,-1);
        int n = nums.size();

        FOR(i,0,n-1) {
            // 用单调增栈计算每个值为最小值的贡献
            // 为什么可以用单调增计算最小值？
            // https://pic.leetcode-cn.com/1613007377-MVxZMC-stackl-1Jl's%20sInallest.png
            // 当前元素 num[stk.back()] 作为峰值能被当成最小值的区间在左右两个开区间内（左右都比当前元素小不能被包含） 
            while (stk.size()>1&&nums[stk.back()]>nums[i]) {
                // 左边界的选择可能 * 右边界的选择可能 * 贡献值
                ans-=1ll*(stk.back()-stk[stk.size()-2])*(i-stk.back())*nums[stk.back()];
                stk.pop_back();
            }
            stk.push_back(i);
        }
        // 最后一个值的贡献
        while (stk.size()>1) {
            ans-=1ll*(stk.back()-stk[stk.size()-2])*(n-stk.back())*nums[stk.back()];
            stk.pop_back();
        }

        FOR(i,0,n-1) {
            while (stk.size()>1&&nums[stk.back()]<nums[i]) {
                ans+=1ll*(stk.back()-stk[stk.size()-2])*(i-stk.back())*nums[stk.back()];
                stk.pop_back();
            }
            stk.push_back(i);
        }
        while (stk.size()>1) {
            ans+=1ll*(stk.back()-stk[stk.size()-2])*(n-stk.back())*nums[stk.back()];
            stk.pop_back();
        }
        return ans;
    }
    // O(n^2)暴力或预处理区间 dp 解法
    // https://leetcode-cn.com/problems/sum-of-subarray-ranges/solution/gong-shui-san-xie-yi-ti-san-jie-qu-jian-wn84z/
    ll solve2(vector<int> &nums) {
        int n = nums.size();
        ll ans=0,mi,mx;
        FOR(i,0,n-1) {
            mi=mx=nums[i];
            FOR(j,i+1,n-1) {
                mi=min(mi,1ll*nums[j]);
                mx=max(mx,1ll*nums[j]);
                ans+=mx-mi;
            }
        }
        return ans;
    }
};