#include <vector>

using namespace std;
//买卖股票的最佳时机 II
// https://blog.nowcoder.net/n/1584cb25f678493a89343d70d4fb560b?from=nowcoder_improve
// I && II 解析
class Solution {
public:
    // 转移同 121、变为不限制交易次数
    int maxProfit(vector<int>& prices) {
        // 比较前一天不持股和前一天空仓的利润-股价 
        // f[1][i]=max(f[1][i-1],f[0][i-1]-prices[i])
        // 比较前一天持股+今天卖出和前一天空仓
        // f[0][i]=max(f[1][i-1]+prices[i],f[0][i-1])
        int f0=0, f1=-prices[0], t, n=prices.size();
        for (int i = 1; i < n;i++) {
            t=f0;
            f0=max(f1+prices[i],f0);
            f1=max(f1,t-prices[i]);
        }
        return f0;
    }
};