
#include <vector>
using namespace std;
// 买卖股票的最佳时机含手续费
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // f[0][i] = max(f[0][i-1], f[1][i-1]+p[i]-fee)
        // f[1][i] = max(f[1][i-1], f[0][i-1]-p[i]) 
        int n = prices.size(),f0=0,f1=-prices[0],t;
        for (int i = 1; i < n; i++) {
            t=f0;
            f0=max(f0,f1+prices[i]-fee);
            f1=max(f1,t-prices[i]);
        }
        return f0;
    }
};