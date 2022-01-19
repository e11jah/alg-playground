#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using PII = pair<int, int>;

int main() {
    int n, v, w, vv, ans = 0, tmp;

    cin >> n >> v;
    vector<PII> v1, v2;
    for (int i = 0; i < n; i++) {
        cin >> w >> vv;
        if (w == 1)
            v1.emplace_back(i + 1, vv);
        else
            v2.emplace_back(i + 1, vv);

    }
    sort(v1.begin(), v1.end(), [](PII l, PII r) {
        return l.second > r.second;
    });
    sort(v2.begin(), v2.end(), [](PII l, PII r) {
        return l.second > r.second;
    });
    int i = 0, j = 0, n2 = v2.size(), n1 = v1.size();
    // 贪心
    for (; v > 1 && j < n2; v -= 2)
        ans += v2[j++].second;
    for (; v > 0 && i < n1; v -= 1)
        ans += v1[i++].second;

    tmp = ans;
    // 空出 2 ，尝试 1 是否能取更大价值
    for (int x = j - 1, y; x >= 0; x--) {
        tmp -= v2[x].second;
        v += 2;
        for (y = i; y < n1 && v > 0; y++)
            tmp += v1[y].second, v -= 1;

        // 尝试失败
        if (tmp <= ans)
            break;

        ans = tmp, i = y, j--;
    }
    cout << ans << endl;

    // 在 i, j 之前都是允许的方案（1,2 都取到最大）
    for (int x = 0; x < j; x++)
        cout << v2[x].first << " ";
    for (int y = 0; y < i; y++)
        cout << v1[y].first << " ";
}
