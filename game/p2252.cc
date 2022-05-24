#include <iostream>
#include <math.h>
using namespace std;

const double fi = (sqrt(5.)+1.)/2.;
void solve() {
    int a,b;
    cin >> a >> b;

    // 巴什博奕 n % (m+1)
    // 威佐夫博弈模板
    if (a>b)
        swap(a,b);
    // bk = ak + k
    int k = b-a;
    // 满足则后手胜
    if (a==(int)(1.*k*fi))
        puts("0");
    else puts("1");

}

int main() {
    solve();
    return 0;
}