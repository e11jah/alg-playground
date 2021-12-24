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

const int M = 1e9 + 7;
const int B = 233;

int get_hash(const string& s) {
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
        // 对于字符串 xyz，其哈希函数值为 xb^2 + yb + z。
        res = (ll)(res * B + s[i]) % M;
    }
    return res;
}

bool cmp(const string& s, const string& t) {
    return get_hash(s) == get_hash(t);
}

int main() {
    // 向上取整做法，无余数 -1 结果加回
//    cout << (2 / 4-1)+1 << endl;

    ios::sync_with_stdio(false);
    int n, r, N = 101 * 2;
    // f[l, r] 表示把从 l 到 r 合并成一堆的最小代价
    int mi[N][N], ma[N][N], s[N], a[N];

    fill(&mi[0][0], &mi[N-1][N-1], INT_MAX);
    memset(ma, 0, sizeof ma);
    memset(s, 0, sizeof s);

    cin >> n;
    for (int i = 1; i <=n; i++) cin >> a[i], a[i+n] = a[i];
    for (int i = 1; i <=2*n ; i++) {
        // 把环存成一条链：即把T存成2*T
        // 如：2 3 4 6 5 4 2 3 4 6 5 4 这样每次枚举i到i+n-1就可以了
        s[i] = s[i - 1] + a[i];
        // i - i 为 0 代价
        mi[i][i] = ma[i][i] = 0;
    }

    // 枚举长度，最大为 n
    for (int len = 2; len <=n; len++) {
        // 枚举起点 （断环为链, 终点小于 2n）
        for (int l = 1; l + len-1 <= 2*n; l++) {
            r = l + len -1;
            // 枚举分割点
            for (int k = l; k < r; k++) {
//                printf("f[%d,%d]=%d; f[%d,%d]=%d; f[%d,%d]=%d; s=%d\n", l, r, mi[l][r], l, k, mi[l][k], k+1, r,
//                       mi[k+1][r], s[r]-s[l-1]);
                mi[l][r] = min(mi[l][r], mi[l][k] + mi[k+1][r] + s[r]-s[l-1]);
                ma[l][r] = max(ma[l][r], ma[l][k] + ma[k+1][r] + s[r]-s[l-1]);

            }
        }
    }
    int maxAns = 0, minAns = INT_MAX;
    for (int i = 1; i < n; i++) {
        maxAns = maxAns > ma[i][i+n-1]? maxAns : ma[i][i+n-1];
        minAns = minAns < mi[i][i+n-1]? minAns : mi[i][i+n-1];
    }

    cout << minAns << endl << maxAns;
}