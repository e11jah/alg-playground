#include <vector>
#include <string>

using namespace std;

#define FOR(i,l,r) for(int i = l; i <= r; i++)

typedef unsigned long long ull;
const int P = 131;

// 字符串哈希
// 双倍经验：末尾补充字符，使整个字符串变回文
// 画图比较正反序字符串相同的回文部分
// https://www.cnblogs.com/-Ackerman/p/11955026.html#
class Solution {
    int n;
public:
    /**
     * 解题思路 2 (100%)
     * 遍历 1~n, 用上法同时计算正逆序哈希, 
     * 由于左边缺字符, 当正逆序哈希相等时说明此子串是回文,
     * 复制剩余部分的逆序到前面即可, 当正逆序哈希相等且 i 最大时得最短回文串。
     */
    string solve2(string s) {
        n = s.size();
        // 正逆序
        ull prefix=0, suffix=0, ppow=1;
        int r;
        FOR(i,1,n) {
            // 逆序哈希的另一种计算方式
            // 正序：((1 + s0)*p + s1)*p + s2 ...
            // 正序 = p^(n-1) + s0*p(n-2) + s2 ...
            // 故逆序 = s0 + s1*p + s2* p^2 +...
            prefix=prefix*P+s[i-1];
            suffix=suffix+s[i-1]*ppow;
            ppow*=P;
            if (prefix==suffix) r = i;
        }
        string t=s.substr(r);
        reverse(t.begin(),t.end());
        return t+s;
    }
    // 顺序存放逆序哈希才可使用此函数计算区间值
    ull get(int l, int r, vector<ull> & h, vector<ull> & p) {
        return h[r]-h[l-1]*p[r-l+1];
    }
    string shortestPalindrome(string s) {
        n = s.size();

        vector<vector<ull>> h(2, vector<ull>(n+2));
        vector<ull> p(n+1);
        p[0]=1;
        // 计算正反 hash
        FOR(i,1,n) {
            h[0][i] = h[0][i-1]*P+(s[i-1]-'a'+1);
            p[i]=p[i-1]*P;
        }

        // 逆序哈希, 顺序存放逆序字符串的哈希值
        for (int i = n, j=1; i> 0;i--, j++)
            h[1][j]=h[1][j-1]*P+(s[i-1]-'a'+1);

        if (h[0][n]==h[1][1]) {
            return s;
        }

        // 左边比右边短，枚举右半部分的每个点
        // 与逆序字符串的右移子串哈希值进行比较, 相等则说明找到最大回文子串, 复制剩下部分即可

        // 默认左边空, 需复制 n-1 个字符到前面
        int r=0;
        for(int i = n; i > 0; i--) {
            // 以 i 为右端点比较逆序子串, 相等则复制剩余部分的逆序到前面, 得最短回文串
            if (h[0][i]==get(n-i+1, n, h[1], p)) {
                r=i;
                break;
            }
        }

        string t=s.substr(r);
        reverse(t.begin(),t.end());
        return t+s;
    }
};