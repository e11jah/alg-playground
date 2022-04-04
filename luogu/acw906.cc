#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> PII;
// 区间分组 贪心
void solve() {
    int n,ok;
    cin >> n;
    vector<PII> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    // 默认按 first 排序
    sort(a.begin(), a.end());
    priority_queue<int,vector<int>,greater<int>> heap;
    for (PII p : a) {
        // 分组中的最小右端点大于当前左端点
        if (heap.empty() || heap.top() >= p.first)
            heap.push(p.second);
        else
            // 更新小根堆
            heap.pop(),heap.push(p.second);
    }
    cout << heap.size();
}

int main() {
    solve();
    return 0;
}