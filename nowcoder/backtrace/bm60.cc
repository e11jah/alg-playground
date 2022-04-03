#include <string>
#include <vector>
using namespace std;
// 括号生成
class Solution {
    int m;
    vector<string> ans;
public:
    void dfs(int l, int r, string s) {
        if (l ==m && r == m) {
            ans.push_back(s);
            return;
        }
        if (l < m)
            dfs(l+1,r,s+"(");
        if (l>r&&r<m)
            dfs(l,r+1,s+")");
    }
    /**
     * 
     * @param n int整型 
     * @return string字符串vector
     */
    vector<string> generateParenthesis(int n) {
        // write code here
        if (n < 1)
            return ans;
        m=n;
        dfs(0,0,"");
        return ans;
    }
};