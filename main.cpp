//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

using PII = pair<int, int>;
typedef long long ll;

void v1() {
    int n , k;
    cin >> n >> k;
    vector<PII> v(k);
    vector<int> sum(n+1), dp(n+1);

    for (int i = 0; i < k; i++) {
        cin >> v[i].first >> v[i].second;
        sum[v[i].first]++;
    }
    sort(v.begin(), v.end(), [](PII l, PII r) {
        return l.first < r.first;
    });
    int cur = k-1;
    // 按总分钟数从后往前遍历
    for (int i = n; i > 0; i--) {
        if (sum[i]<1)
            // 无任务时取上一分钟的空闲时间 + 1
            dp[i] = dp[i+1] + 1;
        else for (int j = 0; j < sum[i]; j++) {
                // 有任务时比较当前空闲时间与放弃该任务时的空闲时间
                dp[i] = dp[i] > dp[i+v[cur].second] ? dp[i] : dp[i+v[cur].second];
                cur--;
            }
    }
    cout << dp[1];
}

/**
 * 二维数组免排序法
 */
void v2() {
    int n, k, a, b;
    cin >> n >> k;
    vector<vector<int>> v(n+1);
    vector<int> dp(n+1);
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        v[a].push_back(b);
    }

    for (int i = n; i > 0; i--) {
        if (v[i].empty())
            dp[i] = dp[i+1] + 1;
        else for (int j = 0; j < v[i].size(); j++)
            dp[i] = dp[i] > dp[i+v[i][j]] ? dp[i] : dp[i+v[i][j]];

    }
    cout << dp[1];
}

int main() {
    v2();
}