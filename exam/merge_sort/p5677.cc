#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll,int> PLI;
#define FOR(i,l,r) for(int i =l; i <=r; i++)
const int N = 2e5+5;
PLI a[N];
int main() {
    int n, c;
    cin >> n;

    FOR(i,1,n)
        cin>>a[i].first, a[i].second=i;

    sort(a+1, a+1+n);
    double t=0, s=0;
    FOR(i,1,n) {
        // 每个人等待时间之和
        s+=t;
        cout << a[i].second << ' ';
        t+=a[i].first;
    }

    printf("\n%.2f", s/n);
    return 0;
}