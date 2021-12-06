#include <iostream>

using namespace std;

string add(string a, string b) {
    int al = a.length(), bl = b.length(), ml = max(al, bl);
    int *A = new int[ml], *B = new int[ml];
    int *V = new int[ml + 1];

    for (int i = al - 1; i >= 0; i--)
        A[al - i] = a[i] - '0';

    for (int i = bl - 1; i >= 0; i--)
        B[bl - i] = b[i] - '0';

    for (int i = 1; i <= ml; i++) {
        V[i] += (A[i] + B[i]);
        V[i + 1] = V[i] / 10;
        V[i] %= 10;
    }
    if (V[ml + 1])
        ml++;
    string res;
    for (int i = ml; i > 0; i--)
        res.append(to_string(V[i]));
    return res;
}

string mul(string a, int b) {
    int al = a.length(), l = al *2;
    int *A = new int[al], *V = new int[l];
    for (int i = al - 1; i >= 0; i--)
        A[al - i] = a[i] - '0';

    for (int i = 1; i <= al; ++i) {
        V[i] += A[i] * b;
        V[i + 1] = V[i] / 10;
        V[i] %= 10;
    }
    while (!V[l])
        l--;

    string res;
    for (int i = max(1, l); i > 0; i--)
        res.append(to_string(V[i]));
    return res;
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
