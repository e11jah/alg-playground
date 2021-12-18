//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

using PII = pair<int, int>;
typedef long long ll;


int main() {
    int n, k, idx;
    cin >> n >> k;
    ll ai;
    vector<ll> sum(n);
    for (int i = 1 ; i < n; i++) {
        cin >> ai;
        sum[i] += sum[i-1] + ai;
    }
    ll ans = sum[n-1], t;
    for (int i = 1; k > 0 && i < n; i++) {
            idx = i - k < 0 ? 0 : i - k;
            t = sum[n-1] - sum[i] + sum[idx];
            ans = t < ans ? t : ans;
    }
    cout << ans;

    return 0;
}