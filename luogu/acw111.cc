#include <vector>
#include <iostream>
#include <queue>

using namespace std;
typedef pair<int,int> PII;

const int N = 5e5+5;
struct cow {
    public:
    int id, l,r,g;
    // 自定义 greater
    bool operator>(const cow& rhs) const
    {
        return r > rhs.r;
    }
};
cow cows[N];
// 畜栏预定 贪心 小根堆
void solve() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++ ) {
        cin >> cows[i].l >> cows[i].r;
        cows[i].id=i;
    }
    // 按照左端点排序
    sort(cows+1,cows+n+1, [](const cow l, const cow r) {
        return l.l < r.l;
    });
    priority_queue<cow, vector<cow>, greater<cow>> heap;
    // 存储 group
    vector<int> g(n+1);
    for (int i = 1; i <= n; i++) {
        // 左端点小于小根堆堆顶的右端点时，开新的分组
        if (heap.empty()|| cows[i].l <= heap.top().r ) {
            // 存储 group 再 push
            cows[i].g=heap.size()+1;
            heap.push(cows[i]);
            g[cows[i].id]=cows[i].g;
        } else {
            cow c = heap.top();
            heap.pop();
            g[cows[i].id]=c.g;
            // 更新 group
            cows[i].g=c.g;
            heap.push(cows[i]);
        }
    }
    cout << heap.size() << endl;
    // 输出每头牛的 group
    for (int i =1; i <= n; i++)
        cout << g[i] << endl;
}

int main() {
    solve();
    return 0;
}