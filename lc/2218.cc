#include <algorithm>
#include <vector>

using namespace std;
//从栈中取出 K 个硬币的最大面值和 前缀和 01 背包
class Solution {
public:
    typedef long long ll;
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        // f[j] i 摞 取 j 个硬币的最大值
        vector<ll> f(k+1, INT_MIN);
        f[0]=0;
        // 当前硬币数
        int c=0,t,n;
        for (vector<int> & v : piles) {
            n=v.size();
            // 前缀和
            for (int i = 1; i < n; i++)
                v[i]+=v[i-1];
            c+=n,c=c<k?c:k;
            // f[i][j]=max(f[i][j],f[i-1][j-w]+v[w]);
            for (int j = c; j > 0; j--) {
                // j >= w
                t=j<n?j:n;
                for (int w = 1; w <= t; w++)
                    f[j]=max(f[j],f[j-w]+v[w-1]);
            }
        }
        return f[k];
    }
};