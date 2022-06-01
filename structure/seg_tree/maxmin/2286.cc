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

typedef long long ll;
typedef pair<int,int> PII;

const int MOD = 1e9+7, N = 5e4+5;

#define lc p<<1
#define rc p<<1|1
#define mid ((l+r)>>1)

class BookMyShow {
    int n, m;
    vector<int> mi;
    vector<ll> sum;
public:
    BookMyShow(int a, int b) {
        n=a,m=b;
        sum.resize(n*4);
        mi.resize(n*4);
    }
    
    inline void push_up(int p) {
        sum[p]=sum[lc]+sum[rc];
        mi[p]=min(mi[lc],mi[rc]);
    }
    
    // 单点+
    inline void add(int idx, int l, int  r, int p, int k) {
        if (l==r) {
            sum[p]+=k,mi[p]+=k;
            return ;
        }
        int m = mid;
        if (idx<=m)
            add(idx,l,m,lc,k);
        else
            add(idx,m+1,r,rc,k);
        push_up(p);
    }
    
    inline ll getSum(int ql, int qr, int l, int r, int p) {
        // 查询区间包含当前区间
        if (ql<=l&&r<=qr) return sum[p];
        ll ans = 0;
        int m = mid;
        // 部分包含
        if (ql <= m) ans+=getSum(ql,qr,l,m,lc);
        if (qr>m) ans+=getSum(ql,qr,m+1,r,rc);
        return ans;
    }
    
    // 查找区间 [1,R] 中满足 min[i] <= val 的最小行数
    inline int index(int l, int r, int p, int R, int val) {
        if (mi[p]>val) return -1;
        if (l==r) return l;
        int m = mid;
        // 左子树查找
        if (mi[lc]<=val) return index(l,mid,lc,R,val);
        if (m<R) return index(mid+1,r,rc,R,val);
        // 右子树
        return -1;
    }

    vector<int> gather(int k, int maxRow) {
        int row = index(1,n,1,maxRow+1,m-k);
        if (row==-1) return {};
        int col = getSum(row,row,1,n,1);
        add(row,1,n,1,k);
        return {row-1,col};
    }
    
    bool scatter(int k, int maxRow) {
        ll left = 1ll*m*(maxRow+1) - getSum(1,maxRow+1,1,n,1);
        if (left < k) return false;
        // 从第一排没坐满的开始
        int row = index(1,n,1,maxRow+1,m-1);
        while (k) {
            int left = m - getSum(row,row,1,n,1);
            if (left>=k) {
                add(row,1,n,1,k);
                return true;
            }
            k-=left;
            add(row,1,n,1,left);
            row++;
        }
        return true;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */