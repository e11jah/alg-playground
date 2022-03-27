#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

const int N=1e5+10;

// 树状数组存放 pos, l, r, 开三倍
ll tre[3*N], tot, n,m, len, pos[N], lr[N][2], nums[N];//, lr[N][2];
vector<ll> dis;

inline ll lowbit(ll x) {
    return x & -x;
}

void add(ll x, ll c) {
    // printf("%lld add %lld\n", x, c);
    while (x <= tot) {
        tre[x]+=c, x+=lowbit(x);
    }
}

ll ask(ll x)  {
    // printf("ask %lld\n", x);
    ll ans=0;
    while(x)
        ans+=tre[x],x-=lowbit(x);
    return ans;
}

ll idx(ll x) {
    // 树状数组下标从 1 开始
    return lower_bound(dis.begin(),dis.end(), x)-dis.begin()+1;
}
// 离散化模板
int main() {
    memset(tre, 0, sizeof(tre));

    scanf("%lld %lld", &n, &m);

    for (int i = 1; i<=n; i++) 
        scanf("%lld %lld", &pos[i], &nums[i]), dis.push_back(pos[i]);
    for (int i = 1; i <= m; i++)
        scanf("%lld %lld", &lr[i][0], &lr[i][1]),dis.push_back(lr[i][0]-1),dis.push_back(lr[i][1]);
    
    sort(dis.begin(),dis.end());
    tot=dis.back();
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    
    tot=idx(tot);

    for (int i = 1; i <= n; i++)
        add(idx(pos[i]),nums[i]);
    
    for (int i = 1; i <= m; i++) 
        printf("%lld\n", ask(idx(lr[i][1]))-ask(idx(lr[i][0]-1)));
    
    return 0;
}