//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

using PII = pair<int, int>;
typedef long long ll;


int main() {
    int n, m, a, b, c;
    cin >> n >> m;

    vector<int> d(n);

    int pre, p;
    for (int i = 0; i < m; i++) {
        cin >> p;
        // i > 0
        if (i) {
            // 记录访问次数差分
            if (p > pre)
                d[pre]++, d[p]--;
            else
                d[p]++, d[pre]--;
        }
        pre = p;
    }
    ll times = 0, ans = 0, t;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        // times[i] 表 从 i 到 i + 1 的访问次数
        // times[i] = times[i-1] + d[i];
        times += d[i];
        t = times * b + c;
        ans += t > a * times ? a * times : t;
    }
    cout << ans;

    return 0;
}