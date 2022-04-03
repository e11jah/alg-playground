#include <iostream>
using namespace std;

typedef long long ll;
int n;
char a[10][10];

bool check(int x, int y) {
    for (int i = 1; i < x; i++) {
        if (a[i][y]=='Q')
            return false;
        for (int j = 1; j <= n; j++) {
            if (i+j==x+y&&a[i][j]=='Q')
                return false;
            if (x-y==i-j&&a[i][j]=='Q')
                return false;
        }
    }
    return true;
}

void dfs(int line) {
    if (line > n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                cout <<a[i][j];
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (check(line, j)) {
            a[line][j]='Q';
            dfs(line+1);
            a[line][j]='.';
        }
    }
}

void solve() {
    cin >> n;

    for(int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j]='.';

    dfs(1);
}

int main() {
    solve();
    return 0;
}