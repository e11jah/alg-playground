//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

using PII = pair<int, int>;
typedef long long ll;


// 大师
void unSolve() {
    int n, d, ans = 0, md = 20000, MOD = 998244353;
    cin >> n;
    vector<int> v(n + 1);
    // dp[i][j] 表示数到第 i 个数，且公差为 j 时有多少种方案
    vector<vector<int>> dp(n + 1, vector<int>(20001));

    for (int i = 1; i <= n; i++)
        cin >> v[i];

    for (int i = 1; i <= n; i++) {
        // 加上所有单塔的方案
        ans++;
        for (int j = i - 1; j; j--) {
            // 计算 i 与 j 的公差（加最大公差处理负数）
            d = v[i] - v[j];
            d = d < 0 ? d + md : d;
            // j 结尾的等差数列追加一个 i ，多一种方案（最长）
            // 以 i 结尾且上一个数是 j 的公差为 k 的等差数列数量是以 j 结尾公差为 k 的等差数列数加一
            dp[i][d] = (dp[i][d] + dp[j][d] + 1) % MOD;
            // 加上 i 与 j 构成 2 个塔的方案，多一个
            ans = (ans + dp[j][d] + 1) % MOD;
        }
    }
    cout << ans;
}

int main() {
    // 向上取整做法，无余数 -1 结果加回
//    cout << (2 / 4-1)+1 << endl;
    int m, s, t;
    cin >> m >> s >> t;
    int s1 = 0, s2 = 0;
    for (int i = 1; i <= t; i++) {
        s2 += 17;
        if (m >= 10)
            s1 += 60, m -= 10;
        else
            m += 4;
        if (s1 > s2)
            s2 = s1;

        if (s1 >= s || s2 >= s) {
            cout << "Yes" << endl << i;
            return 0;
        }
    }

    cout << "No" << endl << max(s1, s2);
}