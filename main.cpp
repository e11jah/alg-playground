//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

using long long = ll;
int main() {
    int n, m;
    long long ans = 0;
    cin >> n >> m;

    vector<int> v(n);
    cin >> v[0];
    int preSum = v[0];
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        preSum += v[i];
        if (preSum > m) {
            preSum -= m;
            ans += preSum;
            preSum = v[i] > preSum ? v[i]-preSum : 0;
        } else
            preSum = v[i];
    }
    if (ans < 1)
        ans = 1;
    cout << ans;

    return 0;
}