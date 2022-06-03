#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
#define FOR(i,l,r) for(int i = l; i <=r; i++)
#define RFOR(i,r,l) for(int i = r; i>=l; i--)
const ll N = 2e5+5;
ll s[N]={0};
void solve() {
    ll n,k;
    cin>>n>>k;
    FOR(i,1,n) {
        cin>>s[i];
        s[i]+=s[i-1];
    }
    // 防止全负数, 取 64 位最小
    ll ans=INT64_MIN,prev=ans;
    FOR(i,k,n-k) {
        prev=max(prev,s[i]-s[i-k]);
        ans=max(ans,prev+s[i+k]-s[i]);
    }
    cout << ans<<"\n";
}

int main() {
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}