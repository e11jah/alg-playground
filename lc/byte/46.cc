#include <vector>

using namespace std;

// 回溯
class Solution {
    int n ;
    int st[10]={0};
public:
    vector<vector<int>> permute(vector<int>& nums) {
        this->n=nums.size();
        vector<vector<int>> ans;
        vector<int> path(n,0);
        dfs(0,ans,nums,path);
        return ans;
    }
    void dfs(int pos,vector<vector<int>> &ans, vector<int> &nums, vector<int>& path) {
        if (pos == n) {
            ans.push_back(path);
            return;
        }
        for (int i = 1; i <= n; i++)
            if (!st[i]) {
                st[i]=1;
                path[pos]=nums[i-1];
                dfs(pos+1,ans,nums,path);
                st[i]=0;
            }
    }
};