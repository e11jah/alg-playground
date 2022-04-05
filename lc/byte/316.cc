#include <string>
#include <vector>

using namespace std;
// 去除重复字母 每个字母 pop x-1 次、记忆化判断是否使用
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size(),t;
        string ans;
        vector<int> cnt(26,0), mp(26,0);
        for ( char c : s)
            cnt[c-'a']++;
        
        for (int i = 0; i < n; i++) {
            t = s[i]-'a';
            if (!mp[t]) {
                // cnt 表示剩余出现次数
                while (!ans.empty() && s[i]<ans.back()&&cnt[ans.back()-'a']>0) {
                    // 字典序小的先， pop 的 下次还可以放入
                    mp[ans.back()-'a']=0;
                    ans.pop_back();
                }
                ans.push_back(s[i]);
                mp[t]=1;
            }
            // 减少次数，未放入则丢弃
            cnt[t]--;
        }
        return ans;
    }
};