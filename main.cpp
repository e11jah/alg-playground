#include <iostream>
#include <vector>

using namespace std;


void f2() {
    ios::sync_with_stdio(false);
    int A[2001] = {0}, B[2001] = {0}, V[4004] = {0};
    string a, b;

    cin >> a >> b;
    int al = a.length(), bl = b.length(), len = al +bl;

    for (int i = al - 1; i >= 0; i--)
        A[al-i] = a[i] - '0';
    for (int i = bl - 1; i >= 0; i--)
        B[bl-i] = b[i] - '0';

    for (int i = 1; i <= al; i++)
        for (int j = 1; j <= bl; j++)
            V[j + i - 1] += A[i] * B[j];

    for (int i = 1; i <= len; i++) {
        V[i+1] += V[i] / 10;
        V[i] %= 10;
    }
    while (!V[len])
        len--;

    for (int i = max(1, len); i > 0; i--)
        cout << V[i];
}

int main() {
    f2();
    return 0;
}
