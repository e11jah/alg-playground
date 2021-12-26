//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

using PII = pair<int, int>;
#define bll __int128

typedef long long ll;

const int N = 120;
int m;
bll pow2[N], memo[N][N], v[N];

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

bll dfs(int l, int r) {
    if (memo[l][r] > -1)
        return memo[l][r];
    if (r-l<1)
        return memo[l][r] = v[l] * pow2[m-r+l];
    return memo[l][r] = max(dfs(l + 1, r) + pow2[m - r + l] * v[l], dfs(l, r - 1) + pow2[m - r + l] * v[r]);
}

int main() {
//    ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
    int n;
    bll ans = 0;
    cin >> n >> m;

    pow2[0] = 1;
    for (int i = 1; i <= m; i++)
        pow2[i] = 2 * pow2[i - 1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            v[j] = read<bll>();

        memset(memo, -1, sizeof(memo));
        ans += dfs(1, m);
    }

    write(ans);
}