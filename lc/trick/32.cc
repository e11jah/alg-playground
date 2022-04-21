struct pos {
    int idx;
    char c;
    pos(int a, char b):idx(a),c(b) {}
};
class Solution {
public:
    char pair(char c) {
        switch(c) {
            case ')': return '(';
            case ']': return '[';
            case '}': return '{';
        }
        return 0;
    }
    
    int longestValidParentheses(string s) {
        int n=s.size(),ans=0;
        vector<pos> stk;
        // 有效括号置 0 无效括号置 1
        // 找连续的 0 的长度
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c==')'||c==']'||c=='}') {
                if (!stk.empty() && stk.back().c==pair(c)) {
                    pos p = stk.back();
                    s[p.idx]=s[i]='0';
                    stk.pop_back();
                    continue;
                }
            }
            stk.emplace_back(i,c);
            s[i]='1';
        }
        // cout << s << endl;
        s.push_back('1');
        int f=0,sl=0;
        while( f < n+1) {
            if (s[f]!='0')
                ans=max(ans,f-sl),sl=f+1;
            f++;
        }
        return ans;
    }
};