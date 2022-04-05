#include <stack>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
// 单调栈 Bad Hair Day S
void solve() {
    ll n,ans=0,t;
    cin >> n;

    stack<int> s;
    // 反向思维 计算当前高度的牛能被前面多少牛看见
    for (int i = 1; i <= n; i++) {
        cin >> t;
        while (!s.empty() && t >= s.top())
            s.pop();
        
        ans+=s.size();
        // 栈底到栈顶单调减，栈底能看见栈中所有牛
        s.push(t);
    }
    cout << ans;
}

int main() {
    solve();
    return 0;
}