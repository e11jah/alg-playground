#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
// 单调栈
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1), f(n+1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // 单调降序, 栈顶<栈底
    stack<int> s;
    for (int i = n; i>0;i--) {
        // f[i] 记录 第 i 个元素之后第一个大于 ai 的元素的下标
        while (!s.empty()&&a[s.top()]<=a[i])
            s.pop();
        
        f[i]=s.empty()?0:s.top();
        s.push(i);
    }
    for (int i = 1; i <= n; i++)
        cout << f[i] << ' ';
}

int main() {
    solve();
    return 0;
}