#include <vector>

using namespace std;
//买卖股票的最佳时机
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int f0=0,f1=-prices[0],t;
        for (int i =1; i < prices.size(); i++) {
            t = f0;
            f0=max(f0, f1+prices[i]);
            f1=max(f1,-prices[i]);
        }
        return f0;
    }
};