#include <iostream>

using namespace std;
typedef long long ll;
const int N = 105;
ll a[N][N],dp[N][N];
int f,v, pos[N];

/**
 * 当各个花瓶中放入不同的花束时，会产生不同的美学效果。
 * 每种花都有一个标识，假设杜鹃花的标识数为1，秋海棠的标识数为2，康乃馨的标识数为3，所有的花束在放入花瓶时必须保持其标识数的顺序，即：
 * 杜鹃花必须放在秋海棠左边的花瓶中，秋海棠必须放在康乃馨左边的花瓶中。
 * 如果花瓶的数目大于花束的数目。则多余的花瓶必须空置，且每个花瓶中只能放一束花。
 * 每种花放在不同的瓶子里会产生不同的美观程度，美观程度可能是正数也可能是负数。
 */
void solve() {
    cin >> f >> v;
    for (int i = 1; i <= f; i++)  {
        for (int j = 1; j <= v; j++)
            cin >> a[i][j];  
    }

    dp[0][0]=0;
    for (int i = 1; i <= f; i++) {
        for (int j = 1; j <= v; j++) {
            if (i==j) 
                dp[i][j]=dp[i-1][j-1]+a[i][j];
            else
                // 当前行选中当前列必须由上一行的前一列转移而来
                dp[i][j]=max(dp[i][j-1],dp[i-1][j-1]+a[i][j]);
        }
    }
    cout << dp[f][v] << endl;
    int x = f;
    while (f) {
        while (dp[f][v]==dp[f][v-1]) v--;
        pos[f]=v;
        f--,v--;
    }
    for (int i = 1; i <= x; i++)
        cout << pos[i] << ' ';
}

int main() {
    solve();
    return 0;
}