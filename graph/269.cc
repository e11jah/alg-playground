#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

#define FOR(i,l,r) for(int i = l; i <=r; i++)
#define RFOR(i,r,l) for(int i = r; i>=l; i--)

#define PLN(n) printf("%lld\n", n)
#define PLN2(a, b) printf("%lld %lld\n", a, b)
#define PLN3(a, b, c) printf("%lld %lld %lld\n", a, b, c)
#define PLN4(a, b, c, d) printf("%lld %lld %lld %lld\n", a, b, c, d)

#define PIN4(a, b, c, d) printf("%d %d %d %d\n", a, b, c, d)
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> PII;

const int MOD = 1e9+7, N = 105;

class Solution {
    int h[31], nex[N*2], to[31], in[31], idx=0, tot=0;
    string ans;
public:
    void add(int a, int b) {
        to[idx]=b;
        nex[idx]=h[a];
        h[a]=idx++;
        ++in[b];
    }
    bool topsort(vector<int> & vis) {
        queue<int> q;
        FOR(i,0,25) 
            if (vis[i]&&!in[i]) q.push(i);
        // 有环
        if (q.empty()) return false;

        while (q.size()) {
            int x = q.front();
            q.pop();
            tot--;
            ans += 'a'+x;
            for (int j = h[x]; j != -1; j = nex[j]) {
                int t = to[j];
                --in[t];
                if (!in[t]) q.push(t);
            }

        }
        return tot==0;
    }
    string alienOrder(vector<string>& words) {
        memset(h, -1, sizeof h);
        int n = words.size();
        vector<int> vis(26);           
            
        FOR(i,0,n-1) {
            for (char & c : words[i])
                tot=vis[c-'a']?tot:tot+1,++vis[c-'a'];
            
            if (!i) continue;

            int c1 = 0, c2 = 0, n = words[i-1].size(), m = words[i].size();
            while (c1 < n && c2 < m && words[i-1][c1]==words[i][c2])
                ++c1,++c2;

            // 不符合字典序要求
            if (c2 == m && c1 != n)
                return "";
            if (c2 < m && c1 < n) 
                add(words[i-1][c1]-'a', words[i][c2]-'a');
        }

        if (tot==1) {
            FOR(i,0,25)
                if (vis[i]) {
                    ans += 'a'+i;
                    return ans;
                }
        }

        if (topsort(vis))
            return ans;
        return "";
    }
};