#include <string>
#include <vector>

using namespace std;

#define FOR(i,l,r) for(int i = l; i <=r; i++)
#define RFOR(i,r,l) for(int i = r; i>=l; i--)
typedef unsigned long long ull;
const int P = 131;
// 求所有能组合成回文的字符串对
class Solution {
    // h 正反方向 hash, 只保存全部长度的 hash
    // p 保存幂
    // ull 自动取模
    ull h[5005][2], p[301];
    int lens[5005];
public:
    bool checkS(int i, int j) {
        // 比较正反字符串 hash
        return (h[i][0]*p[lens[j]]+h[j][0])==(h[j][1]*p[lens[i]]+h[i][1]);
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        ull t;
        int n = words.size(), slen, mlen=0;
        FOR(j,0,n-1) {
            t=0;
            slen=words[j].size();
            lens[j]=slen;
            mlen=max(slen,mlen);
            // 正方向 hash
            FOR(i,0,slen-1)
                t=t*P+words[j][i];
            h[j][0]=t;
            t=0;
            // 反方向 hash
            RFOR(i,slen-1,0)
                t=t*P+words[j][i];
            h[j][1]=t;
        }
        // 保存幂
        p[0]=1;
        FOR(i,1,mlen) p[i]=p[i-1]*P;

        FOR(i,1,n)
            FOR(j,1,n)
                if (i!=j&&checkS(i-1,j-1))
                    ans.push_back({i-1,j-1});
        return ans;
    }
    bool check(string s, int l, int r) {
        while(l<=r) {
            if (s[l]!=s[r])
                return false;
            l++,r--;
        }
        return true;
    }
};