#define FOR(i,l,r) for(int i = l; i <=r; i++)
#define RFOR(i,r,l) for (int i = r; i >= l; i--)
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5+5,P=131;
class Solution {
    ull h[N], p[N];
public:

    long long sumScores(string s) {
        int n = s.size(),len=0,l,r,m,k;
        ll ans=0;
        p[0]=1,h[n+1]=0;

        // 逆序计算哈希
        // s[0] 幂最高, 计算时 l-r
        RFOR(i,n,1) 
            h[i]=h[i+1]*P+s[i-1],p[len+1]=p[len]*P,len++;

        RFOR(i,n-1,0) {
            if (s[i]!=s[0])
                continue;
            // 二分搜索公共前缀长度
            l=1,r=n-i,k=0;
            while (l<=r) {
                m=(l+r)/2;
                // 下标逆序存储字符串哈希时逆序计算
                ull a=h[1]-h[m+1]*p[m], b=h[i+1]-h[i+m+1]*p[m];

                if (a==b) 
                    l=m+1,k=m;
                else r=m-1;
            }
            ans+=k;
        }
        return ans;
    }
};