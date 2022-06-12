class Solution {
public:
    // 统计包含每个点的矩形数目
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        // 排序 hash 二分
        // 按列排序
        sort(rectangles.begin(), rectangles.end(), [](const vector<int> & l, const vector<int> & r) {
            if (l[1]==r[1])
                return l[0]<r[0];
            return l[1]<r[1];
        });
        map<int,vector<int>> mp;
        for (const vector<int> & rr : rectangles)
            mp[rr[1]].push_back(rr[0]);
        int n = points.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            // use & to avoid copy
            for (auto &[k,v] : mp) {
                // y > py 
                if (k < points[i][1])
                    continue;
                // 所有矩阵互不相同
                // count x >= px
                int idx = lower_bound(v.begin(), v.end(), points[i][0])-v.begin();
                ans[i]+=v.size()-idx;
                // cout << "idx "<<v.size()<<' '<<idx<<endl;
            }
            // cout << ans[i]<<endl;
        }
        return ans;
    }
};