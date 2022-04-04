#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
// 无重复字符的最长子串 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n < 2)
            return n;
        vector<int> mp(130,-1);
        int ans=0,st=0;
        for (int i = 0; i < n; i++) {
            if (mp[s[i]]!=-1) {
                ans=max(ans,i-st);
                st=max(st,mp[s[i]]+1);
            }
            mp[s[i]]=i;
        }
        return max(ans,n-st);
    }

    int solve1(string s) {
        unordered_map<char,int> mp;
        int n = s.size();
        if (n < 2)
            return n;
        int ans=0,st=0,t;
        for (int i =0;i < n; i++) {
            if (mp.count(s[i])) {
                t=mp.size();
                ans=max(ans,t);
                // 上一次出现的位置
                t=mp[s[i]];
                for (int j = st; j <= t; j++)
                    mp.erase(s[j]);
                st=t+1;
            }
            mp[s[i]]=i;
        }
        t=mp.size();
        return max(ans,t);
    }
};