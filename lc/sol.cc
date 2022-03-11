#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int vis[10001], n;
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int t, prev, m=0, ans=0;
        n = parents.size();
        vector<int> ps;
        ps.reserve(n);
        for (int i = 0; i < n; i++) {
            prev = parents[i];
            parents[i] = -2;

            t = getPoint(parents);
            ps.push_back(t);
            m = t > m ? t : m;

            parents[i] = prev;
        }
        for (int p : ps)
            ans = p == m ? ans+1 : ans;
        return ans;
    }

    int getPoint(vector<int> &v) {
        memset(vis, 0, sizeof vis);
        int p=0, t;
        for (int i = 0; i < n; i++) {
            if (v[i] != -2) {
                t = dfs(v, i);
                p = p == 0 ? t : p*t;
            }
        }
        return p;
    }

    int dfs(vector<int> &v, int pos) {
        if (pos < 0 || vis[pos] == 1)
            return 0;

        vis[pos]=1;
        return 1 + dfs(v, v[pos]);
    }
};

int main() {
    vector<int> v{-1,2,0,2,0};
    Solution s = Solution();
    cout << s.countHighestScoreNodes(v) << endl;
}