#include <vector>

using namespace std;
// 买卖股票的最佳时机 IV
// 从 III 推公式
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if (n < 1 || k < 1)
            return 0;
        int t, prev;
        vector<vector<int>> f(k+1, vector<int>(2,0));
        // 第 0 天，买入 i 次 都是 -prices[0], 卖出 i 次 都是 0 利润
        for (int i = 1; i <= k; i++)
            f[i][1]=-prices[0];

        for (int i = 1; i < n; i++) {
            // j 次卖出只和 j 次买入有关
            // j 次买入只和前一次卖出有关
            // f[0][0]=0
            prev=0;
            for (int j = 1; j <= k; j++) {
                t=f[j][0];
                f[j][0]=max(f[j][0], f[j][1]+prices[i]);
                f[j][1]=max(f[j][1], prev-prices[i]);
                prev=t;
            }
        }
        return f[k][0];
    }
};