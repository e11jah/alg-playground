//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

using PII = pair<int, int>;
typedef long long ll;


bool check(vector<int> loc, int mid, int m) {
    int pre = 0,n = 0;
    for (int i = 1; i < loc.size(); i++) {
        if (loc[i] - pre < mid)
            n++;
        else
            pre = loc[i];
    }
    return n <= m;
}

int main() {
    int tl, n, m;
    cin >> tl >> n >> m;
    if (n == m) {
        cout << tl;
        return 0;
    }
    vector<int> loc(n + 2);

    for (int i = 1; i <= n; i++)
        cin >> loc[i];

    loc[n + 1] = tl;
    // https://www.luogu.com.cn/blog/HOJQVFNA/qian-tan-er-fen-di-bian-jie-wen-ti
    int l = 1, r = tl, mid;
    // 不记录 mid 时 使用 l < r
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (check(loc, mid, m))
            // + 1 上移至 /2 处
            l = mid;
        else
            r = mid - 1;
    }
    cout << l;
    return 0;
}