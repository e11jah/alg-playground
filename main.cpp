//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    using PII = pair<int, int>;
    int n;
    int s = 0;
    cin >> n;
    vector<PII> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    stable_sort(v.begin(), v.end(), [](PII l, PII r) -> bool {
        // 优先选择先结束的比赛
        return l.second < r.second;
    });
    int curEnd = 0;
    for (PII e : v) {
        if (e.first < curEnd)
            continue;
        s++;
        curEnd = e.second;
    }
    cout << s;
    return 0;
}