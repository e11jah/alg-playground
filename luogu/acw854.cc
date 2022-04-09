#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
const int N = 210, INF=1e9;

int d[N][N];
int n;
// floyd 多源带权（可负权）最短路
void floyd() {
    // 中间点放最上层
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n ; j++)
            for (int k = 1; k <= n; k++)
                    d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
                    
}

void solve() {
    int m,k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i==j)
                d[i][i]=0;
            else d[i][j]=INF;
    int a,b,c;  
    while (m--) {
        cin >> a >> b >> c;
        d[a][b]=min(d[a][b], c);
    }
    floyd();
    
    while (k--) {
        cin >> a >> b;
        if (d[a][b]>INF/2)
            puts("impossible");
        else 
            cout << d[a][b] << endl;
    }
}

int main() {
    solve();
    return 0;
}