//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
int main() {
    string s;
    int k;
    cin >> s >> k;

    for (int j = k; j > 0; j--) {
        for (int i = 0; i < s.size()-1; i++) {
            // 删掉高位比地位大的数字
            if ((s[i] - '0') > (s[i+1]-'0')) {
                s.erase(s.begin() + i);
                k--;
                break;
            }
        }
    }
    // 若高位都比低位小，删除尾部
    if (k) {
        s = s.substr(0, s.size()-k);
    }
    // 去除前导0
    size_t found = s.find_first_not_of('0');
    if (found != string::npos)
        s = s.substr(found);
    cout << s;

    return 0;
}