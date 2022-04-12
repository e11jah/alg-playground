#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,int> PLI;
typedef pair<int,int> PII;
#define FOR(i,l,r) for(int i =l; i <=r; i++)
const int N = 1e6+5;

PII a[N],b[N];
int n, c[N],t[N];
ll ans=0;

void msort(int l, int r) {
    if (l==r)  return;
    int m=(l+r)/2,j=l,k=m+1,s=l;
    msort(l,m),msort(k,r);
    while(j<=m&&k<=r) {
        if (c[j]<=c[k]) t[s++]=c[j++];
        else t[s++]=c[k++], ans+=(m-j+1);
    }
    while(j<=m) t[s++]=c[j++];
    while(k<=r) t[s++]=c[k++];
    FOR(i,l,r)
        c[i]=t[i];
}
// 同 p1966 双倍经验
void solve() {
    cin >>n;
    string s1,s2;
    cin >> s1 >> s2;
    FOR(i,1,n) {
        a[i].first=s1[i-1]-'A', a[i].second=i;
        b[i].first=s2[i-1]-'A', b[i].second=i;
    }
    sort(a+1, a+1+n);
    sort(b+1, b+1+n);

    FOR(i,1,n)
        c[b[i].second]=a[i].second;
    msort(1,n);
    cout << ans;
}

int main() {
    solve();
    return 0;
}