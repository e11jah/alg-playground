#define FOR(i,l,r) for(int i = l; i <=r; i++)
typedef long long ll;
const int MOD=1e9+7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(),c;
        ll t,ans=0;
        vector<int> stk(1,-1);
        // 单调增找最小
        FOR(i,0,n-1) {
            while (stk.size()>1&&arr[stk.back()]>arr[i]) {
                c=stk.back();
                stk.pop_back();
                t=1ll*(c-stk.back())*(i-c)*arr[c]%MOD;
                ans=(ans+t)%MOD;
            }
            stk.push_back(i);
        }
        while (stk.size()>1) {
            c=stk.back(),stk.pop_back();
            t=1ll*(c-stk.back())*(n-c)*arr[c]%MOD;
            ans=(ans+t)%MOD;
        }

        return ans;
    }
};