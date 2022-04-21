class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mp;
        for (int x : tasks)
            mp[x]++;
        int ans=0;
        for (auto [k,v] : mp) {
            if (v==1)
                return -1;
            // 特判
            // % 3 == 1
            // 最后 4 个分两个取
            // % 3 == 2
            if (v%3==0)
                ans+=v/3;
            else ans+=v/3+1;

        }
        return ans;
    }
};