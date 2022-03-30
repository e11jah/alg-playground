#include <iostream>
#include <cstring>

using namespace std;

void solve() {

    int n,m,dp[75][75];
    memset(dp, 0, sizeof(dp));
    //一行两个数字n，m（1<=n<=70，1<=m<=70）用空格隔开，表示篮子数和足球数。
    cin >>n>>m;
    for (int i = 1; i<=m;i++)
        // 只有一个篮子
        dp[1][i]=1;
    for (int i = 1; i <=n;i++)
        // 没有足球
        dp[i][0]=1;
    
    for (int i = 1; i<=n;i++)
        for (int j = 1; j <=m;j++)
            if (i>j)
                dp[i][j]=dp[j][j];
            else dp[i][j]=dp[i-1][j]+dp[i][j-i];
    
    cout << dp[n][m];
}

int main() {
    solve();
    return 0;
}