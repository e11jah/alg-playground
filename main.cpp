//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

//bits/stdc++.h
int main() {
    ios::sync_with_stdio(false);
    int t, m;
    cin >> t >> m;

    int w[10001], c[10001];
    for (int i = 1; i <= m; i++)
        cin >> w[i] >> c[i];

    vector<long long> dp(t+1, 0);

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= t; j++)
            if (j >= w[i])
                dp[j] = max(dp[j], dp[j-w[i]] + c[i]);


    cout << dp[t];

    return 0;
}