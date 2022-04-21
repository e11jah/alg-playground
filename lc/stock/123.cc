#include <vector>

using namespace std;
//买卖股票的最佳时机 III
// 限制买卖 2 次，枚举每种状态，找公式
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int k = 2, t, prev;
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
    // 枚举每种状态
    int solve1(vector<int> & prices) {
        int n=prices.size(), f[3][2];
        // f[0][0][0]=0,f[1][1][0]=-p[0];
        f[0][0]=0,f[1][1]=-prices[0],f[1][0]=0;
        f[2][0]=0,f[2][1]=-prices[0];
        int f10;
        // 首次卖出
        // f[1][0][i] = max(f[1][0][i-1], f[1][1][i-1]+p[i])
        // 二次卖出
        // f[2][0][i] = max(f[2][0][i-1], f[2][1][i-1]+p[i])
        // 首次买入
        // f[1][1][i] = max(f[1][1][i-1], f[0][0][i-1]-p[i])
        // 二次买入
        // f[2][1][i] = max(f[2][1][i-1], f[1][0][i-1]-p[i])
        for (int i =1; i < n; i++) {
            f10=f[1][0];
        
            f[1][0]=max(f[1][0], f[1][1]+prices[i]);
            f[2][0]=max(f[2][0], f[2][1]+prices[i]);
            f[1][1]=max(f[1][1], -prices[i]);
            f[2][1]=max(f[2][1], f10-prices[i]);
        }
        return f[2][0];
    }
};