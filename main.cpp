//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

string mul(string a, int b) {
    string ret;
    reverse(a.begin(), a.end());
    int t = 0;
    for (char c : a) {
        t += (c - '0') * b;
        ret.push_back('0' + (t % 10));
        t /= 10;
    }
    while (t) {
        ret.push_back('0' + (t % 10));
        t /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string divide(const string &a, int b) {
    string ret;
    int t = 0;
    for (char c : a) {
        t = t * 10 + (c - '0');
        if (t >= b)
            ret.push_back('0' + t / b);
        else
            // !!! 中间的 0 不能省略
            ret.push_back('0');
        t %= b;
    }
    // 移除前面的 0
    while (!(ret.front() - '0'))
        ret.erase(ret.begin());
    if (ret.empty())
        ret.push_back('0');
    return ret;
}

bool gt(const string &a, const string &b) {
    int la = a.size(), lb = b.size();
    if (la > lb)
        return true;
    if (la < lb)
        return false;
    for (int i = 0; i < la; i++)
        if ((a[i] - '0') > (b[i] - '0'))
            return true;
    return false;
}

int main() {
    using PII = pair<int, int>;
    int n;
    cin >> n;
    vector<PII> v(n+1);
    for (int i = 0; i < n+1; i++)
        cin >> v[i].first >> v[i].second;

    int cl, cr;
    sort(v.begin()+1, v.end(), [&cl, &cr](PII l, PII r) -> bool {
        cl = l.first * l.second, cr = r.first * r.second;
        if (cl == cr)
            return l.second < r.second;
        return cl < cr;
    });
    string ans = "0";
    string lSum = "1", awards;
    for (int i = 1; i < n + 1; i++) {
        lSum = mul(lSum, v[i - 1].first);
        awards = divide(lSum, v[i].second);
        if (gt(awards, ans))
            ans = awards;
    }
    cout << ans;
//    awards = divide("9018", 9);
//    cout << endl << awards;

    return 0;
}