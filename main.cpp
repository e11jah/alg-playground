//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

using PII = pair<int, int>;
typedef long long ll;


void dp() {
    int n;
    cin >> n;
    vector<int> p1(n + 1), p2(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        cin >> p1[i];
    for (int i = 1; i <= n; i++)
        cin >> p2[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if (p1[i] == p2[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    cout << dp[n][n];
}

/**
 * 转为 lis 问题
 */
void lis() {
    int n;
    cin >> n;
    vector<int> p1(n), p2(n), idx(n + 1), cl;
    for (int i = 0; i < n; i++) {
        cin >> p1[i];
        idx[p1[i]] = i + 1;
    }
    /** 由于 p2 单调递增，公共元素列中单调递增的即为最长公共子序列
     */
    for (int i = 0; i < n; i++) {
        cin >> p2[i];
        // 用 0 区别, 长度 n+1
        if (idx[p2[i]] > 0)
            // p1 乱序，cl 中存放公共元素
            cl.push_back(idx[p2[i]]);
    }

    vector<int> lis;
    for (int & e : cl) {
        auto it = lower_bound(lis.begin(), lis.end(), e);
        // 公共子序列中找不到即前面都比 e 小
        if (it == lis.end())
            lis.push_back(e);
        else
            // 否则将第一个比 e 大的元素修改为 e（降低了子序列中 e 位置的大小，使序列增长的概率增大）
            *it = e;
    }
    cout << lis.size();
}

int main() {
    lis();
    return 0;
}