#include <vector>
#include <string>

using namespace std;
// 最长公共子序列
class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    string LCS(string s1, string s2) {
        // write code here
        int a = s1.size(), b=s2.size();
        if (a==0||b==0)
            return "-1";
        vector<vector<int>> f(a+1, vector<int>(b+1, 0));
        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++) 
                f[i+1][j+1]=s1[i]==s2[j]?f[i][j]+1:max(f[i+1][j], f[i][j+1]);
            
        string ans;
        for (int i = a, j=b;f[i][j];) {
            if (s1[i-1] == s2[j-1])
                ans.push_back(s1[i-1]),i--,j--;
            else if (f[i-1][j]<f[i][j-1])
                j--;
            else
                i--;
        }
        reverse(ans.begin(), ans.end());
        return ans.empty()?"-1":ans;
    }
};