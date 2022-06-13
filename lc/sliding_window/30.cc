#define FOR(i,l,r) for(int i = l; i <=r; i++)
typedef unsigned long long ull;
const int P = 131, N = 1e4 +5;
class Solution {
    int n,m,k;
public:

    vector<int> findSubstring(string s, vector<string>& words) {
        n = s.size(), m=words.size(),k=words[0].size();

        int len = m*k;
        map<string,int> mp,window;
        vector<int> ans;
        for (const string & w : words) 
            mp[w]++;

        // 滑动窗口 找子串中是否有给定单词列表的任意排列
        string st;
        int j,x;
        FOR(i,0,n-len) {
            j = i + len;
            window.clear();
            for(x = i; x < j; x+= k) {
                st=s.substr(x,k);
                if (!mp.count(st)) break;
                window[st]++;
            }
            
            if (x==j&&mp==window)
                ans.push_back(i);
        }
        return ans;
    }
    
};