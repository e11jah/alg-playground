#include <vector>

using namespace std;
//  最佳买卖股票时机含冷冻期
class Solution {
public:
    int solve2(vector<int>& prices) {
        int x = prices[0], n = prices.size();
        vector<vector<int>> f(3, vector<int>(n,0));
        f[1][0]=-prices[0];
        for (int i = 1; i < n; i++) {
            // 买入
            f[1][i]=max(f[1][i-1], f[0][i-1]-prices[i]);
            // 卖出进入冷冻
            f[2][i]=max(f[0][i-1], f[1][i-1]+prices[i]);
            // 空仓或解冻
            f[0][i]=max(f[0][i-1], f[2][i-1]);
        }
        return max(f[0][n-1],f[2][n-1]);
    }
    int maxProfit(vector<int>& prices) {
        // 前一天冷冻，今天解冻
        // f[0][0][i] = max(f[1][0][i-1],f[0][0][i-1])
        // i 天冷冻
        // f[1][0][i] = f[0][1][i-1]+p[i]
        // f[0][1][i] = max(f[0][1][i-1], f[0][0][i-1]-p[i])

        int n = prices.size(), f[2][2]={0},t;
        f[0][1]=-prices[0];
        for (int i = 1; i < n; i++) {
            t=f[0][0];
            if (i > 1)
                f[0][0]=max(f[1][0], f[0][0]);
            f[1][0]=f[0][1]+prices[i];
            f[0][1]=max(f[0][1], t-prices[i]);
        } 
        return max(f[0][0], f[1][0]);
    }
};