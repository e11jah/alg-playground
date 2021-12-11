//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    using PII = pair<int, int>;
    int n, t;
    cin >> n >> t;
    // mi, vi
    vector<PII> wv(n);

    for (int i = 0; i < n; i++)
        cin >> wv[i].first >> wv[i].second;

    sort(wv.begin(), wv.end(), [&](const PII l, const PII r) -> bool {
        // tips 分数比较大小
        return  l.second * r.first > r.second * l.first;
    });

    // 6 5 4 3
    // 40 - 20 + 20  s = 60 + 100 + 80 = 240
    double s = 0;
    for (PII p : wv) {
        if (!t)
            break;
        if (t >= p.first) {
            t -= p.first;
            s += 1.0 * p.second;
        } else {
            s += 1.0 * t / p.first * p.second;
            t -= t;
        }
    }
    cout.precision(2);
    cout << fixed << s;
    return 0;
}