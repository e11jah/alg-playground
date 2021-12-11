//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 使用 pair 记录 idx
    using PII = pair<int, int>;
    int n, t;
    long long s = 0;
    cin >> n;
    vector<PII> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i+1;
    }

    stable_sort(arr.begin(), arr.end(), [](PII l, PII r) -> bool {
        return l.first < r.first;
    });
    t = n-1;
    for (PII e : arr) {
        s += t * e.first;
        t--;
        cout << e.second << " ";
    }
    // cout.precision(2);
    // cout << endl << fixed << (double) s / n;
    printf("\n%.2lf",  (double) s / n);
    return 0;
}