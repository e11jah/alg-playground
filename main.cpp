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

#define N 500010
struct Trie {
public:
    int nex[N][26], cnt = 0;
    bool exist[N];
    Trie(){
        memset(nex, 0, sizeof nex);
        memset(exist, 0, sizeof exist);
    }

    void insert(string s) {  // 插入字符串
        int p = 0, c;
        for (int i = 0; s[i]; i++) {
            c = s[i] - 'a';
            if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
            p = nex[p][c];
        }
        exist[p] = true;
    }

    bool find(string s) {  // 查找字符串
        int p = 0, c;
        for (int i = 0; i < s[i]; i++) {
            c = s[i] - 'a';
            if (!nex[p][c]) return false;
            p = nex[p][c];
        }
        return exist[p];
    }
};

int main() {
//    ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
    int n, m;
    cin >> n;
    map<string, int> mp;
    Trie tr = Trie();

    string t;
    while (n--) {
        cin >> t;
        tr.insert(t);
    }
    cin >> m;
    while (m--) {
        cin >> t;
        if (mp[t]) {
            cout << "REPEAT" << endl;
            continue;
        }
        if (tr.find(t))
            cout << "OK" << endl;
        else
            cout << "WRONG" << endl;
        mp[t]++;
    }
}