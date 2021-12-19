//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

using PII = pair<int, int>;
typedef long long ll;


int main() {
    int n, s, a, b, h, ans = 0, idx = 0;
    cin >> n >> s >> a >> b;
    h = a + b;
    vector<PII> apples;
    apples.reserve(n);
    PII p;
    for (int i = 0; i < n; i++) {
        cin >> p.first >> p.second;
        if (p.first <= h)
            apples.emplace_back(p.first, p.second);
    }
    sort(apples.begin(), apples.end(), [](PII l, PII r) -> bool {
        return l.second < r.second;
    });
    while (s >= 0 && idx < apples.size() && s >= apples[idx].second) {
        s -= apples[idx++].second;
        ans ++;
    }
    cout << ans;

    return 0;
}