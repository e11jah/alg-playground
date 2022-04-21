class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), ans=0;
        vector<int> l(n,1);
        for (int i = 1; i < n; i++) 
            if (ratings[i]>ratings[i-1]) l[i]=l[i-1]+1;
        
        int prev=1,t;
        for (int i = n-1; i>=0; i--) {
            t=1;
            if (i<n-1&&ratings[i]>ratings[i+1])
                t=prev+1;
            l[i]=max(t,l[i]);
            prev=l[i];
            ans+=l[i];
        }
        return ans;
    }
};