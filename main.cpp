//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

void v1() {
    int n, cur, m, mi, t;
    ll ans = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end(), [](int l, int r) {
        return l < r;
    });
    cur = v[n-1];
    ans += cur * cur;
    v.pop_back();
    for (int j = 1; j < n; j++) {
        m = 0;
        for (int i = 0; i < v.size(); i++) {
            t = abs(cur - v[i]);
            if (t > m)
                m = t, mi = i;
        }
        ans += m * m;
        cur = v[mi];
        v.erase(v.begin()+mi);
    }
    cout << ans;
}
int main() {
    int n;
    ll ans = 0;
    cin >> n;
    vector<int> arr(301, 0);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr.begin()+1, arr.begin()+n+1);

    int l = 0, r = n, k=1, t;
    while (l < r) {
        t = arr[r] - arr[l];
        ans += t * t;
        // 奇数次 左跳右, 下次反之
        if (k&1)
            l++;
        // 偶数次 右跳左
        else
            r--;
        k++;
    }
    cout << ans;

    return 0;
}