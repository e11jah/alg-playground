//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

using PII = pair<int, int>;
typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    int n, m, a;
    cin >> n >> m >> a;
    int x = (n -1)/ a  + 1, y = (m-1)/a+1;

    cout << (ll) x*y;
}