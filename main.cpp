#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string in;
    getline(cin, in, static_cast<char>(EOF));

    vector<pair<int, int>> scores11(1);
    vector<pair<int, int>> scores21(1);
    int a = 0, b = 0;
    for (int i = 0; i < (int)in.length() && in[i] != 'E';i++) {
        if (in[i] == '\n')
            continue;

        if (in[i] == 'W') {
            scores11[a].first++;
            scores21[b].first++;
        } else if (in[i] == 'L') {
            scores11[a].second++;
            scores21[b].second++;
        }
        auto p11 = scores11[a];
        auto p21 = scores21[b];

        if ((p11.first > 10 && p11.first - p11.second > 1) || (p11.second > 10 && p11.second - p11.first > 1)) {
            a++;
            scores11.emplace_back(0, 0);
        }
        if ((p21.first > 20 && p21.first - p21.second > 1) || (p21.second > 20 && p21.second - p21.first > 1)) {
            b++;
            scores21.emplace_back(0, 0);
        }
    }

    for (auto & i : scores11)
        cout << i.first << ":" << i.second << endl;
    cout << endl;
    for (auto & i : scores21)
        cout << i.first << ":" << i.second << endl;

    return 0;
}
