
#include <vector>
#include <algorithm>
using namespace std;

// 分发糖果 贪心
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> v(n,1);
        // 从左向右遍历，比前一个分高的给多一个
        for (int i = 1; i < n; i++) {
            if (ratings[i]>ratings[i-1])
                v[i]=v[i-1]+1;
        }
        // 从右向左遍历
        int prev=1,ans=v[n-1];
        for (int i = n-2; i >=0; i--) {
            // 比前一个分高，右边遍历的值 = 前一个 + 1
            if (ratings[i]>ratings[i+1])
                // 取最大值，同时满足左右边的要求
                v[i]=max(v[i], prev+1);
            // 记录前一个值，累加答案
            prev=v[i],ans+=v[i];
        }
        return ans;
    }
};