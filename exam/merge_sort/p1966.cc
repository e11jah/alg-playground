#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+5, MOD=1e8-3; 
#define FOR(x,l,r) for(int x=l; x<=r; x++)
typedef long long ll;
typedef pair<ll,int> PLI;
int n;
PLI a[N], b[N];
int t[N], c[N];
ll ans=0;
void merge_sort(int l, int r) {
    if (l==r)
        return;
    int m=(l+r)/2, j=l,k=m+1,s=l;
    merge_sort(l,m), merge_sort(m+1,r);
    while (j<=m&&k<=r) {
        if (c[j]<=c[k])
            t[s++]=c[j++];
        else  t[s++]=c[k++], ans=(ans+(m-j+1))%MOD;
    }
    while (j<=m)
        t[s++]=c[j++];
    while (k<=r)
        t[s++]=c[k++];
    FOR(i,l,r)
        c[i]=t[i];
}
// 火柴排队 逆序对
// 百度 4.12 笔试出处
void solve() {
    cin >> n;

    FOR(i,1, n) 
        cin>>a[i].first, a[i].second=i;
    FOR(i,1,n)
        cin>>b[i].first, b[i].second=i;

    // sort(b+1,b+1+n);
    // 可证两个序列有序时两列火柴之间距离最小
    // 证: ∑(ai-bi)^2 =∑(ai^2+bi^2-2*ai*bi)
    // 求最小时, -2*ai*bi起决定性因素
    // 即当 ∑(ai*bi) 最大时 -2*∑(ai*bi) 取得最小
    // 当两个序列同序时 ∑(ai*bi) 取最大

    // 两序列排序后, 取排序后结果下标编号的逆序对
    // 	A：2 3 1 4->1 2 3 4对应原编号为：3 1 2 4
	//  B：3 2 1 4->1 2 3 4对应原编号为：3 2 1 4
    sort(a+1, a+1+n);
    sort(b+1, b+1+n);

    // 用数组映射 b 的下标到 a 的下标
    // 将两个序列调整为同序, 即得到距离最小的序列
    // 其中的逆序对即为交换次数
    FOR(i,1,n) {
        c[b[i].second]=a[i].second;
    }
    merge_sort(1,n);
    cout << ans;
}

int main() {
    solve();
    return 0;
}