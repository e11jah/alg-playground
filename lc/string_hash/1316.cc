#include <vector>
#include <string>
#include <map>
using namespace std;

#define FOR(i, l, r) for (int i = l; i <= r; i++)

typedef unsigned long long ull;
const int P = 131;

class Solution {
public:
    ull get(int l, int r, vector<ull> &h,vector<ull> &p) {
        return h[r]-h[l-1]*p[r-l+1];
    }
    int distinctEchoSubstrings(string text) {
        return solve1(text);
    }
    int solve1(string text) {
        int n = text.size();

        int ans=0;
        vector<ull> h(n+1), p(n+1,1);

        FOR(i,1,n) {
            h[i]=h[i-1]*P + text[i-1]-'a'+1;
            p[i]=p[i-1]*P;
        }
        ull t;
        map<ull,int> vis;
        // 枚举 1 到 n/2 的长度
        FOR(len,0,n/2) {
            FOR(i,1,n-2*len-1) {
                t=get(i,i+len,h,p);

                if (!vis[t]&&get(i,i+len,h,p)==get(i+len+1,i+len+1+len,h,p))
                    ans++,vis[t]++;
            }
        }
        return ans;
    }
};