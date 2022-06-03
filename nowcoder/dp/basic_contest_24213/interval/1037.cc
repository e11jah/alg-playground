#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
#define FOR(i,l,r) for(int i = l; i <=r; i++)
#define RFOR(i,r,l) for(int i = r; i>=l; i--)

const int N = 2e2+5;

ll f[35][35];
int r[35][35];

void dfs(int s, int e) {
    if (e<s) return;
    if (s==e) {
        cout << s << ' ';
        return;
    }
    int x = r[s][e];
    cout << x << ' ';

    dfs(s, x-1);
    dfs(x+1, e);
}

void solve() {
    int n,j;
    cin >> n;
    FOR(i,1,n)
        cin >> f[i][i];
    ll t;
    FOR(l,1,n-1) {
        FOR(i,1,n-l) {
            j=i+l;
            FOR(k,i,j) {
                t = f[i][j];
                if (i==k)
                    f[i][j]=max(f[i][j], f[k][k]+f[k+1][j]);
                else if (k==j)
                    f[i][j]=max(f[i][j], f[k][k]+f[i][k-1]);
                else
                    f[i][j]=max(f[i][j],f[i][k-1]*f[k+1][j]+f[k][k]);
                if (f[i][j]>t)
                    r[i][j]=k;
            }
        }
    }
    cout << f[1][n] << endl;
    
    dfs(1,n);
//     FOR(i,0,n) {
//         FOR(j,0,n)
//             cout << r[i][j] << ' ';
//         cout << endl;
//     }
}

int main() {
    solve();
    return 0;
}
