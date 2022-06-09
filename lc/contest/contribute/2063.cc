#define FOR(i,l,r) for(int i = l; i <=r; i++)
typedef long long ll;

class Solution {
    char target[5]={'a','e','i','o','u'};
public:
    bool check(char x) {
        FOR(i,0,4)
            if (x==target[i]) return true;
        return false;
    }
    long long countVowels(string word) {
        int n = word.size();
        ll ans=0;

        vector<ll> dp(n+1);
        FOR(i,1,n) {
            dp[i]=dp[i-1];
            if (check(word[i-1])) 
                dp[i]+=i;
            ans+=dp[i];
        }
        FOR(i,0,n)
            cout << dp[i] << ' ';
        cout << endl;
        return ans;
    }
};