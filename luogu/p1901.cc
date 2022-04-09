#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> PII;
void solve() {
    int n,ans=0;
    cin >> n;
    vector<int> s, f(n+1);
    vector<PII> a(n+1);
    // 遍历两个方向，找最大值
    for (int i = 1; i <= n; i++)  {
        cin >> a[i].first>>a[i].second;
        while (!s.empty() && a[i].first>a[s.back()].first) {
            f[i]+=a[s.back()].second,s.pop_back(),ans=max(ans,f[i]);
        }
        s.push_back(i);
    }
    s.clear();
    for (int i = n; i > 0; i--) {
        while (!s.empty() && a[i].first > a[s.back()].first) {
            f[i]+=a[s.back()].second,s.pop_back(),ans=max(ans,f[i]);
        }
        s.push_back(i);
    }
    cout << ans;
}

int main() {
    solve();
    return 0;
}