#include <stack>

#include <iostream>
#include <vector>
using namespace std;

// 单调栈
void solve() {
    int n,t;
    cin >> n;

    vector<int> f(n+1,0),a(n+1);
    stack<int> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        while (!s.empty() && a[i]>a[s.top()]) {
            f[s.top()]=i,s.pop();
        }
        s.push(i);
    }
    for (int i = 1; i <= n; i++)
        cout << f[i]<<endl;
}

int main() {
    solve();
    return 0;
}