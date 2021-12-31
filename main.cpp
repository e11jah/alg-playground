//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

using PII = pair<int, int>;
#define bll __int128

typedef long long ll;

template<typename T>
inline T
read() {  // 声明 template 类,要求提供输入的类型T,并以此类型定义内联函数 read()
    T sum = 0, fl = 1;  // 将 sum,fl 和 ch 以输入的类型定义
    int ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-') fl = -1;
    for (; isdigit(ch); ch = getchar()) sum = sum * 10 + ch - '0';
    return sum * fl;
}

inline void write(__int128 x) {
    static __int128 sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48);  // 48 是 '0'
}


#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))

int main() {
    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    std::cin.tie(nullptr);
    int m, n, t;
    cin >> m >>  n;

    int a[1001], b[1001], c[1001],  dp[1001];
    map<int, int>k ;
    map<int, vector<int>> mp;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        // 分组内取号
        k[c[i]]++;
        // 记录分组 x 内序号为 x 的物品 idx
        mp[c[i]].push_back(i);
    }

    memset(dp, 0, sizeof dp);
    // dp i j k  第 i 个 组，重量 j，组内序号 x
    for (int i = 1; k[i] > 0 && i < 1001; i++) {
        for (int j = m; j >= 0; j--) {
            // 分组内遍历
            for (int x = 0; x < k[i]; x++) {
                t = mp[i][x];
                if (j >= a[t])
                    /**
                     * 决策
                     * max(f[i-1][j], f[i-1][j-w1]+v1, f[i-1][j-w2]+v2, ...)
                     */
                    dp[j] = max(dp[j], dp[j-a[t]] + b[t]);
            }
        }
    }

    cout << dp[m];
}