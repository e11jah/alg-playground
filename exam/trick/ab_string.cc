#include <iostream>


using namespace std;

const int MOD = 1e9+7;
typedef long long ll;
// 360编程题ab串
void solve() {
    string s;
    cin >> s;

    /**
     * 小明得到一个只包含a,b两个字符的字符串，但是小明不希望在这个字符串里a出现在b左边。
     * 现在他可以将”ab”这样的子串替换成”bba”，
     * 在原串中的相对位置不变。输出小明最少需要操作多少次才能让一个给定字符串所有a都在b的右边。
     * 
     */
    int ans=0, b=0;
    // ab -> bba
    // a 后移 1 位就产生多一个 b
    // a 后移到所有 b 后 = a 后移 b 的数量，同时 b 的数量翻倍
    // 从后往前数 b 的数量
    for (int  i = s.size()-1; i >=0; i--) {
        if (s[i]=='b')
            b++;
        else
            ans=(ans+b)%MOD, b*=2, b%=MOD;
    }
    cout << ans;
}

int main() {
    solve();
    return 0;
}