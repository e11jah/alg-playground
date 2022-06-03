#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N = 2e3;

// 双倍经验 P7302 数据加强版
// i 时刻位置 j 的馅饼分数
int f[N][105]={0},dx[5]={-2,-1,0,1,2};
// 记录位置
int opt[N][105];
void solve() {
    int w,h;
    cin >> w >> h;
    int st, col, v, p, t, maxTime=0;
//     while (!cin.eof()) {

    while(cin >> st >> col >> v >> p) {
        //不能某一秒末被接到!!
        if ((h-1)%v) continue;
        // 最后一行不计
        t=st+(h-1)/v;
        f[t][col]+=p;
        maxTime=max(maxTime,t);
    }
    int cur=(w+1)/2,ans=0,pos,op;

    // 倒着走, 走到起始点不用遍历最后一行
    for (int i = maxTime; i >= 0; i--) {
        for (int j = 1; j <= w; j++) {
            t=0,op=0;
            for (int k = 0; k<5; k++) {
                pos=j+dx[k];
                if (pos<1||pos>w) continue;
                if (f[i+1][pos]>t) {
                    // 记录转移状态和移动步数
                    t=f[i+1][pos],op=dx[k];
                }
            }
            f[i][j]+=t,opt[i][j]=op;
            
        }
    }

    cout << f[0][cur] <<endl;
    int x=0,y=cur;
    // 重放
    while (maxTime--) {
        cout << opt[x][y] << endl;
        op=opt[x][y];
        x++,y+=op;
    }
}

int main() {
    solve();
    return 0;
}