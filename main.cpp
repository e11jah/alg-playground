//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

using PII = pair<int, int>;
typedef long long ll;

const char *UP="0ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void parseRC(string &s) {
    int i=0, j=0,r=0,c=0;
    int v[s.size()+1];
    // 计算 r,c
    // skip 'R'
    for (++i;isdigit(s[i]);i++)
        (r*=10)+=s[i]-'0';
    // skip 'C'
    for(++i;s[i];i++)
        (c*=10)+=s[i]-'0';

    // 余 0 时多 -1 （如 z = 26 余 0 必须 -1 ，避免除不尽）
    for (;c;c=c/26-!(c%26))
            v[++j]=c%26 ? c % 26 : 26;

    for (;j;--j)
        // cout 与 printf 混用 cf 认不出
        putchar(UP[v[j]]);
    printf("%d\n", r);
}

void parse(const string &s) {
    int i = 0, r = 0, c = 0;
    // 次方包含在 前项乘积中
    for (; isupper(s[i]); i++)
        (c *= 26) += s[i]-'A'+1;
    for (; s[i];i++)
        (r*=10)+=s[i]-'0';
    printf("R%dC%d\n", r, c);
}

int main() {

    ios::sync_with_stdio(false);
    int n, r, N= 250, dp[N][N], ans = 0;
    cin >> n;
    memset(dp, 0, sizeof dp);
    // 不需要断环成链
    for (int i = 1; i <= n; i++)
        cin >> dp[i][i];


    for (int len = 2; len <= n; len ++) {
        for (int l = 1; l+len-1 <= n; l++) {
            r = l + len-1;
            for (int k = l; k < r; k++) {
                if (dp[l][k] == dp[k+1][r] && dp[l][k] > 0) {
                    dp[l][r] = max(dp[l][r], dp[l][k] + 1), ans = max(ans, dp[l][r]);
//                    printf("dp[%d, %d], k: %d, %d ->dp[l][k]: %d\n", l, r, k, dp[l][r], dp[l][k]);
                }
            }
        }
    }
    cout << ans;
}