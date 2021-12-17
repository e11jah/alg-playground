//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int memo[5005], in[5005], MOD = 80112002, ans = 0;

int dfs(const vector<vector<int>> &mp, int i) {
    if (mp[i].empty())
        return memo[i] = 1;

    int m = 0;
    for (int e : mp[i]) {
        m += memo[e] ? memo[e] : dfs(mp, e);
        m %= MOD;
    }

    return memo[i] = m;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    memset(memo, 0, sizeof memo);
    memset(in, 0, sizeof in);
    vector<vector<int>> mp(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        in[a]++;
        mp[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        if (!in[i])
            ans = (ans + dfs(mp, i)) % MOD;

    cout << ans;
    return 0;
}