#include <algorithm>
#include <iostream>
#include <vector>
/**
 * 归并排序与逆序对
 * 
 * 计算逆序对板子题
 */

using namespace std;
const int N = 5e5+5;
typedef long long ll;

int n, a[N], t[N];
ll ans=0;
#define FOR(x,j,k) for(int x= j; x <=k; x++)

// 归并排序
void mergeSort(int l, int r) {
    if (l==r)
        return;
    int m=(l+r)/2,j=l,k=m+1,cur=l;
    mergeSort(l,m),mergeSort(m+1,r);
    //归并
    while(j<=m&&k<=r) {
        if (a[j]<=a[k])
            t[cur++]=a[j++];
        else
            // 左边小于右边不构成逆序对
            // 当右边小于左边的数时, 由于已经有序, 
            // 右边的这个数必然小于 (m-i+1) 个数，即有 (m-i+1) 个逆序对
            t[cur++]=a[k++], ans+=m-j+1;
    }
    while (j<=m)
        t[cur++]=a[j++];
    while(k<=r)
        t[cur++]=a[k++];
    // t 是中间数组
    FOR(i,l,r)
        a[i]=t[i];
}

// 归并排序解法
void solve() {
    cin >> n;
    FOR(i,1,n){ 
        cin>>a[i];
    }
    mergeSort(1,n);

    cout<<ans;
}

// 树状数组和 离散化数组长度
ll tr[N], len;
vector<ll> dis;
ll idx(ll x) {
    return lower_bound(dis.begin(), dis.end(), x)-dis.begin()+1;
}
// 树状数组解法
// 核心逻辑 离散化, 维护 a[i] 的数量
// 统计 i - query(a[i]) 得到前面的序列中数值比 a[i] 大的个数（即逆序对数量）
// query(a[i]) 得到 前面序列中所有比 a[i] 小的数值数量
// 值域小的时候树状数组更快
inline ll lowbit(ll x) {
    return x&-x;
}
inline void add(ll x, ll k) {
    while (x<=n)
        tr[x]+=k, x+=lowbit(x);
}
inline ll ask(ll x) {
    ll ans=0;
    while(x)
        ans+=tr[x],x-=lowbit(x);
    return ans;
}
void solve2() {
    cin>>n;
    FOR(i,1,n)
        cin>>a[i],dis.push_back(a[i]);
    sort(dis.begin(), dis.end());
    dis.erase(unique(dis.begin(),dis.end()), dis.end());
    len=dis.size();
    FOR(i,1,n) {
        // 减去 a[1] ~ a[n] 的前缀和必须先加上自己
        add(idx(a[i]),1);
        // 注意离散化
        ans+=i-ask(idx(a[i]));
    }
    cout << ans;
}

int main() {
    // solve();
    solve2();
    return 0;
}