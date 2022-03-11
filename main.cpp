//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
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

void f2() {
    int n, mp[1001], sz = 0;
    memset(mp, 0, sizeof mp);
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (mp[arr[i]] < 1)
            sz++;
        mp[arr[i]]++;
    }
    sort(arr.begin(), arr.end());

    cout << sz << endl << arr[0] << " ";
    for (int i = 1; i < n; i++)
        if ((arr[i] ^ arr[i - 1]) != 0)
            cout << arr[i] << " ";
}

int main() {
    ios::sync_with_stdio(false);
    int n, l, h;
    cin >> n;
    vector<int> s;
    int a[100001],b[100001];

    while (n--) {
        s.clear();
        cin >> l;
        s.reserve(l);
        for (int i = 0; i < l; i++)
            cin >> a[i];
        for (int i = 0; i < l; i++)
            cin >> b[i];

        h = 0;
        for (int i = 0; i < l; i++) {
            s.push_back(a[i]);
            while (s.back() == b[h]) {
                s.pop_back();
                h++;
                if (s.empty())
                    break;
            }
        }
        if (s.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

//    f2();
//    cin.tie(nullptr);
//    std::cin.tie(nullptr);
//    int m, n, t;
//    cin >> n >> m;
//
//    int mx[30][30], dp[201][201];
//
//    for (int i = 1; i <= n; i++)
//        cin >> a[i] >> b[i];
//
//    memset(dp, 0, sizeof dp);
//    for (int i = 1; i <= n; i++) {
//        for (int j = m; j >= a[i]; j--) {
//            for (int k = t; k >= b[i]; k--) {
//                dp[j][k] = max(dp[j][k], dp[j - a[i]][k - b[i]] + 1);
//            }
//        }
//    }
//    cout << dp[m][t];
}