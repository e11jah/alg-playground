#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FOR(i,l,r) for(int i = l; i <=r; i++)
#define RFOR(i,r,l) for(int i = r; i>=l; i--)

#define PLN(n) printf("%lld\n", n)
#define PLN2(a, b) printf("%lld %lld\n", a, b)
#define PLN3(a, b, c) printf("%lld %lld %lld\n", a, b, c)
#define PLN4(a, b, c, d) printf("%lld %lld %lld %lld\n", a, b, c, d)

#define PIN4(a, b, c, d) printf("%d %d %d %d\n", a, b, c, d)
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> PII;

const int MOD = 1e9+7;

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        // 维护最大被删除时刻，单调严格减
        vector<PII> st;
        int ans=0;
        for (int x : nums) {
            int mt = 0;
            while (st.size()&&st.back().f<=x) 
                mt=max(mt,st.back().s),st.pop_back();
            if (st.size()) ++mt;
            ans=max(ans,mt);
            st.emplace_back(x,mt);
        }

        return ans;
    }
};