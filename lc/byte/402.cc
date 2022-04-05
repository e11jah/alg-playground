#include <string>
using namespace std;
// 移掉 k 位数字 单调栈 仅 pop k 次
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (k>=n)
            return "0";
        string s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && num[i]<s.back()&&k>0)
                s.pop_back(),k--;
            s.push_back(num[i]);
        }
        while (s[0]=='0'&&s.size()>1)
            s.erase(s.begin());
        while (k&&!s.empty())
            s.pop_back(),k--;
        return s==""?"0":s;
    }
};