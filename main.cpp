//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

using PII = pair<int, int>;
typedef long long ll;


int main() {
    int n, w, cnt = 0, pre, q;
    cin >> w >> n;
    vector<int> v(n), val(n+1), len(n+1);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end(), greater());
    for (int e : v) {
        q = 0, pre = w;
        for (int i = cnt; i > 0; i--)
            if (len[i] < 2 && val[i] + e <= w && val[i] < pre)
                q = i, pre = val[i];

        if (!q)
            q = ++cnt;

        val[q]+=e, len[q]++;
    }
    cout << cnt;
    return 0;
}