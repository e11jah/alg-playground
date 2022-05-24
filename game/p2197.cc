#include <iostream>

#define FOR(i,l,r) for(int i = l; i <=r; i++)
#define RFOR(i,r,l) for(int i = r; i>=l; i--)
using namespace std;

void solve() {
    int n,x,s;
    cin >> n;
    FOR(i,1,n) {
        cin >> x;
        if (i==1)
            s=x;
        else
            s^=x;
    }
    if (s)
        puts("Yes");
    else puts("No");
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}