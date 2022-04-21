#include <vector>

using namespace std;
// 买卖股票的最佳时机 IV
// 从 III 推公式
class Solution {
public:
    int solve2(int k, vector<int> &prices) {
        // f[0][i][k]
        // f[1][i][k]
        // i 省略
        int n = prices.size();
        if (n < 1 || k < 1) return 0;
        vector<vector<int>> f(2, vector<int>(k+1));
        // 初始化状态
        for (int i = 1; i <=k; i++)
            f[1][i]=-prices[0];

        for (int i = 1; i < n; i++) {
           for (int j = 1; j <= k; j++) {
               // 买入和前一次卖出相关
               f[1][j]=max(f[1][j], f[0][j-1]-prices[i]);
               // 卖出和当前买入相关
               f[0][j]=max(f[0][j], f[1][j]+prices[i]);
           }
        }
        return f[0][k];
    }
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