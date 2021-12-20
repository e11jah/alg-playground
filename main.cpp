//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

using PII = pair<int, int>;
typedef long long ll;

int main() {
    int h, l1 = 0, l2 = 0;
    vector<int> v, idx, remains;
    while (cin >> h) {
        v.push_back(h);
    }
    int n = v.size();
    vector<int> lds(n), lis(n);
    lds[0] = lis[0] = v[0];
    for (int i = 1; i < n; i++) {
        if (lds[l1] >= v[i])
            lds[++l1] = v[i];
        else
            // 默认只能对上升序列使用，对下降序列使用需更换为 greater
            *upper_bound(lds.begin(), lds.begin()+l1, v[i], greater()) = v[i];

        if (lis[l2] < v[i])
            lis[++l2] = v[i];
        else
            *lower_bound(lis.begin(), lis.begin()+l2, v[i]) = v[i];
    }
    cout << l1+1 << endl << l2+1;
}