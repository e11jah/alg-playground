#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(i,l,r) for(int i = l; i <=r; i++)
#define RFOR(i,r,l) for(int i = r; i>=l; i--)
const int N = 1e5+5;

void solve() {
    int i = 1, x;
    // 最多拦截导弹数 = 最长不上升子序列
    // 最少配备多少套 = 最长上升子序列
    // 反证, 对于所有比 x 高的炮弹势必不能用同一套系统
    // 如果 lis 数量不能 cover, 该序列不构成最长上升子序列
    vector<int> lis, lds;
    while (cin>>x) {
        if (lis.empty()||x>lis.back())
            lis.push_back(x);
        else *lower_bound(lis.begin(), lis.end(), x)=x;
        
        if (lds.empty()||x<=lds.back())
            lds.push_back(x);
        else *lower_bound(lds.begin(), lds.end(), x, [](const int& l, const int & r) {
            return l>r;
        })=x;
    }
    cout << lds.size() << endl << lis.size();
}

int main() {
    solve();
    return 0;
}