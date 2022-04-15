#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define FOR(i,l,r) for(int i = l; i <=r; i++)

const int N = 210;
int f[N][N], f2[N][N], s[N]={0};
// 石子合并
void solve() {
    int n,t;
    cin >> n;
    // 断环成链
    FOR(i,1,n) {
        cin >> t;
        s[i]=s[i-1]+t;
    }
    // 前缀和, 表示区间合并代价
    FOR(i,n+1,2*n)
        s[i]=s[i-1]+s[i-n]-s[i-n-1];
    memset(f,0x3f,sizeof f);
    memset(f2,-0x3f,sizeof f2);
    FOR(i,1,2*n) 
        f[i][i]=f2[i][i]=0;
    FOR(len,1,n-1) {
        FOR(i,1,2*n-len) {
            int j = i+len;
            FOR(k,i,j-1) {
                // 合并时加上区间代价
                f[i][j]=min(f[i][j], f[i][k]+f[k+1][j]+s[j]-s[i-1]);
                f2[i][j]=max(f2[i][j], f2[i][k]+f2[k+1][j]+s[j]-s[i-1]);
            }
        }
    }
    int a1=0x3f3f3f3f, a2=0;
    FOR(i,1,n+1) {
        // 取最小
        a1=min(a1,f[i][i+n-1]);
        // 取最大
        a2=max(a2, f2[i][i+n-1]);
    }
    cout << a1 << endl << a2;
}

int main() {
    solve();
    return 0;
}