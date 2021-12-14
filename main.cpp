//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n, m = -(1<<30), s = 0;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (s > 0)
            s += v[i];
        else
            s = v[i];

        m = m > s ? m : s;
    }

    cout << m;
    return 0;
}