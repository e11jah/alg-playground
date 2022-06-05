#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
#define FOR(i,l,r) for(int i = l; i <=r; i++)
#define RFOR(i,r,l) for(int i = r; i>=l; i--)

const int N = 1e3+5;

void solve() {
    int l=1,r=4e6,m,x,n;
    cin >> n;
    while (l<=r) {
        m=(l+r)/2;
        cout << "? "<<m <<endl;
        cin >> x;
        if (x==1) r=m-1;
        else l=m+1;
    }
    int ans=l;
    for (int i = 2; i <= n; i++) {
        cout << "? "<<l/i<<endl;
        cin >> x;
        // 太宽则 h 达不到 i
        if (x==i)
            ans=min(ans,l/i*x);
    }
    cout << "! "<<ans; 
}

int main() {
    solve();
    return 0;
}