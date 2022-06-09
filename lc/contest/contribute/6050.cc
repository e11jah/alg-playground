#define FOR(i,l,r) for(int i = l; i <=r; i++)
typedef long long ll;
class Solution {

public:
    // https://leetcode-cn.com/problems/total-appeal-of-a-string/solution/by-endlesscheng-g405/
    ll appealSum(string s) {
        int n = s.size(),t,j;
        vector<int> loc(26,-1);
        ll ans=0, sum=0;
        FOR(i,0,n-1) {
            // s[i] 未出现过的话，对所有以 s[i] 为结尾的子串作贡献
            // s[i] 出现过，则对上一次出现的坐标 j 之后的子串作贡献
            t=s[i]-'a';
            // sum 表示以 s[i] 结尾的子串的引力和
            sum+=i-loc[t];
            ans+=sum;
            loc[t]=i;
        }
        return ans;
    }
};