#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // 等差求和
    long long sum(long long x) {
        return (1 + x) * x / 2;
    }
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size(), cur = 0;
        long long ans = n;
        int l = 1;

        for (int i = 1; i < n; i++) {
            if (prices[i] + 1== prices[i-1]) {
                l++;
            } else {
                ans += sum(l-1);
                l = 1;
            }
        }
        if (l > 1)
            ans += sum(l-1);

        return ans;
    }
};

int main() {
    vector<int> tt = {10,9,2,5,3,7,101,18};
    auto s = new Solution;
//    cout << s->lengthOfLIS(tt);
}



