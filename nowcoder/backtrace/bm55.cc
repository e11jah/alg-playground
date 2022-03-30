
#include <vector>

using namespace std;

//给出一组数字，返回该组数字的所有排列
class Solution {
    vector<vector<int> > ans;
    int n;
public:
    void swap (int & a, int & b) {
        int t=a;
        a=b;
        b=t;
    }
    void dfs(int pos, vector<int>&data) {
        if (pos ==n) {
            ans.push_back(data);
            return;
        }
        for (int i = pos; i < n; i++) {
            swap(data[i],data[pos]);
            dfs(pos+1, data);
            swap(data[i],data[pos]);
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        n = num.size();

       dfs(0, num);
        return ans;
    }
};