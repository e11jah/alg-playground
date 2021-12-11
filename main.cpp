//#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, s, t;
    cin >> n;
    // map 保持有序
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> t;
        mp[t]++;
    }

    s = 0;
    while (mp.size() > 1) {
        // 优先取最小的值（即使相同）
        auto it = mp.begin(), it2 = mp.begin();
        if (it->second < 2)
            it2++;
        t = it->first + it2->first;
        // val--
        it->second--;
        it2->second--;
        if (!it->second)
            mp.erase(it);
        if (it != it2 && !it2->second)
            mp.erase(it2);
        // 重新放回
        mp[t]++;
        s+=t;
    }
    cout << s;
    return 0;
}