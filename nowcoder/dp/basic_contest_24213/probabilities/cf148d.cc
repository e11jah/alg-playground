#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
#define FOR(i,l,r) for(int i = l; i <=r; i++)
#define RFOR(i,r,l) for(int i = r; i>=l; i--)

void solve2() {
    int w,b;
    cin >> w >> b;
    double d,p=0,q=1.;
    // 数学解法
    // 去掉 dragon 二次抽的
    for (int s=w+b,k=0;k<s;--s,++k) {
        d=q*w/s,p+=d,q-=d;
        // 减去抽过的
        q-=q*w/(--s);
    }
    printf("%.9lf",p);
}
// dfs 记忆化搜索解法
double f[1005][1005];
double dfs(int w, int b) {
    if (f[w][b]) return f[w][b];
    if (w==0) return 0.;
    if (b==0) return 1.;
    // 只有一只黑
    if (b==1) return f[w][b]=1.*w/(w+1);
    double s=0.0;
    // 抽中白
    s+=1.*w/(w+b);
    // 抽两黑跑白
    s+=1.*b/(w+b)*(b-1)/(w+b-1)*w/(w+b-2)*dfs(w-1,b-2);
    if (b>=3)
        // 抽两黑跑黑
        s+=1.*b/(w+b)*(b-1)/(w+b-1)*(b-2)/(w+b-2)*dfs(w,b-3);
    return f[w][b]=s;
}

void solve() {
    int w,b;
    cin >> w >> b;
    double d,p,q=1;
    printf("%.9lf", dfs(w,b));
}

void solve3() {
    int w,b;
    cin >> w >> b;
    FOR(i,1,w)
        // 一黑
        f[i][0]=1.,f[i][1]=1.*w/(w+1);

    FOR(i,1,w) {
        FOR(j,1,b) {
            f[i][j]=1.*i/(i+j);
            if (j>=2)
                // 抽两黑跑白
                f[i][j]+=1.*j/(i+j)*(j-1)/(j+i-1)*i/(i+j-2)*f[i-1][j-2];
            if (j>=3)
                // 抽两黑跑黑
                f[i][j]+=1.*j/(i+j)*(j-1)/(i+j-1)*(j-2)/(i+j-2)*f[i][j-3];
        }
    }

    printf("%.9lf", f[w][b]);
}

int main() {
    solve3();
    return 0;
}