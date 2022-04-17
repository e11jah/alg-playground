#include <vector>
#include <string>
#include <iostream>
#include <climits>
using namespace std;
typedef long long ll;

/*
所谓回文数就是一个数字，从左边读和从右边读的结果都是一样的，例如12321。

现在有一个只包含1、2、3、4的数字，你可以通过在任意位置增加一位数字或者删除一位数字来将其变换成一个回文数。但是增加或删除不同数字所需要的代价是不一样的。

已知增加和删除每个数字的代价如下：

增加一个1，代价：100；删除一个1，代价：120。

增加一个2，代价：200；删除一个2，代价：350。

增加一个3，代价：360；删除一个3，代价：200。

增加一个4，代价：220；删除一个4，代价：320。

请问如何通过最少的代价将一个数字变换为一个回文数。当然，如果一个数字本身已经是一个回文数（包括一位数，例如：2），那么变换的代价为0。
*/
void solve() {
    string s;
    cin >> s;

    ll add[5]={0, 100, 200, 360, 220},
        rm[5]={0, 120, 350, 200, 320};

    int n = s.size();
    // 初始化为 0 直接赋值
    vector<vector<ll>> f(n+1, vector<ll>(n+1, 0));

    for (int len=1; len < n; len++) {
        for (int i = 1; i+len<=n; i++) {
            int j = i+len;
            int l=s[i-1]-'0',r=s[j-1]-'0';

            // 直接赋值
            if (s[i-1]==s[j-1])
                f[i][j]=f[i+1][j-1];
            else 
                f[i][j]=min(min(f[i+1][j]+add[l], f[i+1][j]+rm[l]),
                    min(f[i][j-1]+add[r], f[i][j-1]+rm[r]));
        }
    }
    cout<<f[1][n];
}

int main() {
    solve();
    return 0;
}