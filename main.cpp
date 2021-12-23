//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

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

PII getTime(const string &t) {
    size_t f = t.find_first_of(':');
    string sh = t.substr(0, f), sm = t.substr(f + 1);
    int h = 0, m = 0;
    for (char c : sh)
        h = h * 10 + c - '0';
    for (char c : sm)
        m = m * 10 + c - '0';
    return {h, m};
}

int n, totalMin;
vector<int> t, c, p, dp;

// 多重背包板子
void v1() {


    int maxTimes;
    // dp 下标含义 第 i 个
    for (int i = 0; i < n; i++) {
        // j 剩余时间（背包容量）
        for (int j = totalMin; j >= 0; j--) {
            // 看无限次时取总时间能看的最大次数
            maxTimes = p[i] < 1 ? totalMin / t[i] : p[i];
            // 枚举每种看的次数方案 (容量 j >= 次数 * 价值)
            for (int k = 1; k <= maxTimes && j >= k * t[i]; k++) {
                // 加上的价值要乘上次数
                dp[j] = max(dp[j], dp[j - k * t[i]] + k * c[i]);
            }
        }
    }
    cout << dp[totalMin];
}

// 多重背包 二进制优化
void v2() {
    for (int i = 0; i < n; i++) {
        // 完全背包
        if (p[i] < 1 || t[i] * p[i] > totalMin) {
            for (int j = t[i]; j <= totalMin; j++)
                dp[j] = max(dp[j], dp[j - t[i]] + c[i]);
        } else {
            // 分堆, 每次对比 减去容量的，故分堆后与遍历 p[i] 次效果一样
            for (int k = 1; k <= p[i]; k <<= 1) {
                // 01 背包
                for (int j = totalMin; j >= k * t[i]; j--)
                    dp[j] = max(dp[j], dp[j - k * t[i]] + k * c[i]);
                p[i] -= k;
            }
            // 剩余的数量再次进行 01 背包
            if (p[i])
                for (int j = totalMin; j >= p[i] * t[i]; j--)
                    dp[j] = max(dp[j], dp[j - p[i] * t[i]] + p[i] * c[i]);
        }
    }
    cout << dp[totalMin];
}

int main() {
    string st, end;
    cin >> st >> end;
    PII now = getTime(st), run = getTime(end);

    if (run.first < now.first)
        run.first += 24;
    totalMin = run.second + 60 * (run.first - now.first) - now.second;

    cin >> n;
    t = vector<int>(n), c = vector<int>(n), p = vector<int>(n), dp = vector<int>(totalMin + 1);

    for (int i = 0; i < n; i++)
        cin >> t[i] >> c[i] >> p[i];

    v2();
}