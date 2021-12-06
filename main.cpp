#include <iostream>

using namespace std;

string add(string a, string b) {
    string ret, tmp;
    int t = 0;
    if (b.size() > a.size()) {
        tmp = a;
        a = b;
        b = tmp;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < a.size(); i++) {
        t += a[i] - '0';
        if (i < b.size())
            t += b[i] - '0';
        ret.push_back('0' + (t % 10));
        t /= 10;
    }
    if (t)
        ret.push_back('0' + t);
    reverse(ret.begin(), ret.end());
    return ret;
}

string mul(string a, int b) {
    string ret;
    int t = 0;
    reverse(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++) {
        t += (a[i] - '0') * b;
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

int main() {
    ios::sync_with_stdio(false);
    int x;
    string ans = "1";
    string fact[55] = {""};
    fact[1] = "1";

    cin >> x;

    for (int i = 2; i <= x; ++i) {
        fact[i] = mul(fact[i - 1], i);
        ans = add(ans, fact[i]);
    }
    cout << ans;
    return 0;
}
