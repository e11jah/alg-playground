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
    int m, v, n, t;
    int a[101], b[101], c[101], dp[201][201];
    string path[201][201];
    cin >> m >> v >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> c[i];

    memset(dp, 0, sizeof dp);
    // dp i j k  第 i 个物品，重量 j，阻力 k
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= a[i]; j--) {
            for (int k = v; k >= b[i]; k--) {
                t = dp[j - a[i]][k - b[i]] + c[i];
                if (t > dp[j][k])
                    path[j][k] = path[j - a[i]][k - b[i]] + char(i);
                dp[j][k] = max(dp[j][k], t);
            }
        }
    }
    cout << dp[m][v] << endl;
    for (char cc : path[m][v])
        cout << int(cc) << " ";
}