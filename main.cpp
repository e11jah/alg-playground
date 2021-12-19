//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

using PII = pair<int, int>;
typedef long long ll;


int main() {
    int n, cnt = 0, pre, q;
    cin >> n;
    // 数值小的在队头, len 记录队伍长度
    vector<int> v(n), end(n+1), len(n+1);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    // 排序，后面的元素都大于当前所有队列的队尾
    sort(v.begin(), v.end());
    // 题意：使得人数最少的组人数最多，即所有队伍（连续序列）的人数都尽可能接近
    for (int i = 0; i < n; i++) {
        // pre 最短队伍长度; q 队伍 idx
        pre = n, q = 0;
        for (int j = 1; j <= cnt; j++)
            // 找到当前元素能加入的长度最短的队伍
            if (end[j] + 1 == v[i] && len[j] < pre)
                q = j, pre = len[j];

        if (!q)
            end[++cnt] = v[i], len[cnt]++;
        else
            end[q] = v[i], len[q]++;

    }
    q = n;
    for (int i = 1; i <= cnt; i++)
        q = len[i] < q ? len[i] : q;

    cout << q;
    return 0;
}