
#include <vector>

using namespace std;
// 无重复元素 的整数数组 找 和为 target 的不同组合
// 同一个数字可以无限制选取
// dfs 回溯 
class Solution {
    int n;
public:
    void dfs(vector<vector<int>> & ans, vector<int> &v, vector<int>& t, int pos, int sum, int target) {
        // cout << sum << ' '<< endl;
        if (sum >= target) {
            if (sum == target)
                ans.push_back(t);
            return;
        }
        
        for (int i = pos; i < n; i++) {
            int x = v[i];
            t.push_back(x);
            sum+=x;
            // 从 i 之后选取，保证后所有组合的数字选取数量不同
            dfs(ans,v,t,i,sum,target);
            sum-=x;
            t.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> t;
        n = candidates.size();
        dfs(ans,candidates,t,0, 0,target);
        return ans;
    }
};