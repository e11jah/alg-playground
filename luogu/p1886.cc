#include <iostream>

using namespace std;

const int N = 1e6+5;
int qi[N], qx[N], a[N];
void solve() {
    int n, k,hi=1,hx=1,ti=0,tx=0;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        while (hi<=ti&&i-qi[hi]>=k)
            hi++;
        
        while (hi<=ti && a[qi[ti]]>a[i])
            ti--;
        
        qi[++ti]=i;
        if (i >= k) 
            cout << a[qi[hi]] << ' '; 
    }
    cout << endl;
    // 单调队列
    for (int i = 1; i <= n; i++) {
        while (hx<=tx & i-qx[hx]>=k)
            hx++;
        while (hx<=tx && a[qx[tx]]<a[i])
            tx--;
        qx[++tx]=i;
        if (i >= k)
            cout << a[qx[hx]] << ' '; 
    }
}

int main() {
    solve();
    return 0;
}