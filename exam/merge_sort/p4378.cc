#include <iostream>
#include <algorithm>


using namespace std;
typedef long long ll;
typedef pair<ll,int> PLI;
#define FOR(i,l,r) for(int i =l; i <=r; i++)
const int N = 1e6+5;
ll n;
PLI a[N];
int ans=0;

/**
考虑一次冒泡排序的交换，减小对应1个位子上的1个逆序对。
但是对于每一个位子所需要减小的逆序对数量是不一样的。
对于每一趟，消去每一个位子上1个逆序对 。 所以趟数就是每个位子上的数产生逆序对数的最大值。
 */


void solve() {
    cin>>n;

    FOR(i,1,n) 
        cin >> a[i].first, a[i].second=i;
    sort(a+1, a+1+n);
    FOR(i,1,n)
        ans=max(ans,a[i].second-i);
    cout <<ans+1;
}

int main() {
    solve();
    return 0;
}