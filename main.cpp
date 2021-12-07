#include <iostream>
#include <vector>

using namespace std;

int mod_negative(int a, int b) {
    return (b + (a%b)) % b;
}
//bits/stdc++.h
int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    vector<pair<string, int>> people;
    people.reserve(n);
    int cur, right, cnt;
    string tmp;

    for (int i = 0; i < n; i++) {
        cin >> cur >> tmp;
        people.emplace_back(tmp, cur);
    }
    cur = 0;
    for (int i = 0; i < m; i++) {
        cin >> right >> cnt;
        // 朝内
        if (!people[cur].second) {
            // 向左 = 向上
            if (!right)
                cur = (cur + mod_negative(-cnt, n)) % n;
            else// 向右 = 向下
                cur = (cur + cnt) % n;
        } else {// 朝外
            if (!right)// 向左 = 向下
                cur = (cur + cnt) % n;
            else// 向右 = 向上
                cur = (cur + mod_negative(-cnt, n)) % n;
        }
    }
    cout << people[cur].first;
    return 0;
}
