class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> & l, const vector<int> & r) {
            return l[0]<r[0];
        });
        vector<vector<int>> ans;
        int n = intervals.size();
        ans.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            if (intervals[i][0]<=ans.back()[1]) {
                ans.back()[0]=min(ans.back()[0], intervals[i][0]);
                ans.back()[1]=max(ans.back()[1], intervals[i][1]);
            } else ans.push_back(intervals[i]);
        }
        return ans;
    }
};