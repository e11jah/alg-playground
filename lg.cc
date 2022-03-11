#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using PII = pair<int, int>;


void swap(int &a, int &b) {
    int t = a;
    a=b, b=t;
}

int main() {
    vector<int> v1 = {2, 3};
    swap(v1[0], v1[1]);
    cout << v1[0] << endl;
    string s, e, step;
    cin >> s >> e;
    int sx, ex, sy, ey, ans=0;
    vector<string> steps;
    while (s != e) {
        sx = s[0] - 'a', ex = e[0] - 'a';
        sy = s[1] - '1', ey = e[1] - '1';

        step.clear();
        if (sx != ex) {
            if (sx < ex)
                s[0] = 'a' + sx + 1, step.push_back('R');
            else
                s[0] = 'a' + sx - 1, step.push_back('L');
        }
        if (sy != ey) {
            if (sy < ey)
                s[1] = '1' + sy + 1, step.push_back('U');
            else
                s[1] = '1' + sy - 1, step.push_back('D');
        }
        ans ++;
        steps.push_back(step);
    }

    cout << ans <<endl;
    for (const string& st : steps)
        cout << st << endl;
}
