//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

using PII = pair<int, int>;
#define bll __int128

typedef long long ll;

template<typename T>
inline T
read() {  // 声明 template 类,要求提供输入的类型T,并以此类型定义内联函数 read()
    T sum = 0, fl = 1;  // 将 sum,fl 和 ch 以输入的类型定义
    int ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-') fl = -1;
    for (; isdigit(ch); ch = getchar()) sum = sum * 10 + ch - '0';
    return sum * fl;
}

inline void write(__int128 x) {
    static __int128 sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48);  // 48 是 '0'
}


#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))

int main() {
//    ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
    int n, op, len, tot = 0;
    cin >> n;
    map<int, int> mp;
    while (n--) {
        cin >> op >> len;

        if (op == 1) {
            if (mp[len])
                cout << "Already Exist" << endl;
            else
                mp[len]++, tot++;
        }
        if (op == 2) {
            if (tot < 1) {
                cout << "Empty" << endl;
            } else if (mp[len]) {
                cout << len << endl;
                mp.erase(len), tot--;
            } else {
                mp[len]++;
                auto itBe = mp.find(len);
                auto itAf = itBe;
                itAf++;
                // 特判 begin, end
                if (itBe == mp.begin()) {
                    cout << itAf->first << endl;
                    mp.erase(itAf);
                } else if (itAf == mp.end()){
                    cout << (--itBe)->first << endl;
                    mp.erase(itBe);

                    // 长度比较
                }else if ((len - (--itBe)->first) > (itAf->first - len )) {
                    cout << itAf->first << endl;
                    mp.erase(itAf);
                } else {
                    cout << itBe->first << endl;
                    mp.erase(itBe);
                }
                mp.erase(len);
                tot--;
            }
        }

    }
}