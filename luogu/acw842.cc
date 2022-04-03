#include <iostream>
#include <vector>
using namespace std;

int n ;
int a[10], path[10], st[10]={0};

void dfs(int pos) {
    if (pos == n) {
        for (int i = 0; i < n; i++)
            cout << path[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!st[i]) {
            st[i]=1;
            path[pos]=i;
            dfs(pos+1);
            st[i]=0;
        }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        a[i]=i;
    dfs(0);
}

int main() {
    solve();
    return 0;
}
