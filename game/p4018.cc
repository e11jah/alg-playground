#include <iostream>


using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n%6)
        puts("October wins!");
    else puts("Roy wins!");
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}