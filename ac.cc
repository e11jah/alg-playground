#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    // 请在此输入您的代码

    int m;
    cin >> m;
    queue<string> vip;
    queue<string> normal;
    string line, op, name, q;

    for (int i = 0; i < m; i++) {
        cin >> line;
        istringstream is(line);
        is >> op;

        if (op.compare("IN") == 0) {
            is >> name;
            is >> q;

            if (q.compare("V") == 0) {
                vip.push(name);
            } else {
                normal.push(name);
            }
        } else {
            is >> q;

            if (q.compare("V") == 0) {
                vip.pop();
            } else {
                normal.pop();
            }
        }
    }

    while (!vip.empty()) {
        cout << vip.front() << endl;
        vip.pop();
    }
    while (!normal.empty()) {
        cout << normal.front() << endl;
        normal.pop();
    }

    return 0;
}