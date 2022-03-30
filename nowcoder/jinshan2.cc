#include <iostream>
#include <vector>
using namespace std;
const int MOD=1e9+7;
void solve() {
    int n;
    cin >> n;
    if (n <=3) {
        cout << 1;
        return;
    }
    vector<int> v(3,1);
    for (int i = 4; i<=n;i++) {
        v.push_back((v.back()+v[v.size()-3])%MOD);
    }
    cout << v.back();
}

int main() {
    solve();
    return 0;
}