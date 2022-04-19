#include <iostream>

#include <string>
using namespace std;
typedef unsigned long long ull;
#define FOR(i,l,r) for(int i = l; i <=r; i++)
const int N = 1e5+5, P=131;
// h 存放哈希值, p 存放 P 的幂
int n, m;
ull h[N], p[N];
string s;

// 获取子串 hash
ull get(int l, int r) {
    return h[r]-h[l-1]*p[r-l+1];
}
// 字符串哈希
void solve() {
    cin >> n >> m >> s;

    p[0]=1;
    FOR(i,1,n) {
        p[i]=p[i-1]*P;
        h[i]=h[i-1]*P+s[i-1];
    }

    while (m--) {
        int l1,r1,l2,r2;
        cin >> l1>>r1>>l2>>r2;
        if (get(l1,r1)==get(l2,r2)) puts("Yes");
        else puts("No");
    }
}

int main() {
    solve();
    return 0;
}