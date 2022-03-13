#include <iostream>
#include <vector>

using namespace std;

// 单调栈
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    // cin >> n >> m;
    int h = 0, t = n-1;
    vector<int> v(n), qi(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        // cin >> v[i];
        if (i == 0) {
            printf("0\n");
            // cout << 0 << endl;
        }

        // 队头 > 左边界
        if (h <=t && qi[h] < i-m+1)
            h++;
        // 值 <= tail, 出队
        while (h<=t && v[i]<=v[qi[t]])
            t--;
        // 入队
        qi[++t] = i;

        if (i < n-1)
            printf("%d\n", v[qi[h]]);
            // cout << v[qi[h]] << endl;
    }
}