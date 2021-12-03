#include <iostream>
#include <cstring>
#include <vector>
//#include <algorithm>

using namespace std;


void f2() {
    int dp[1100] = {0};
    int n, x;
    cin >> n >> x;

    int w[2000], win[2000], fail[2000];
    /**
     * 01背包
     */
    for (int i = 1; i <= n; i++) {
        cin >> fail[i] >> win[i] >> w[i];
        // 压缩到一维时须从后向前推（否则后面的 j 使用的 j-w[i] 不是 i-1 行的）
        for (int j = x; j >= 0; j--) {
            if (j < w[i])
                dp[j] += fail[i];
            else
                dp[j] = max(dp[j] + fail[i], dp[j-w[i]] + win[i]);
        }
    }
    cout << dp[x] * 5ll << endl;
}

int main() {
    f2();
    return 0;
}
