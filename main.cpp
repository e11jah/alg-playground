//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n, d = 0;
    cin >> n;
    int arr[100005];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 1; i < n; i++)
        d = arr[i] >  arr[i-1] ? d + arr[i]-arr[i-1] : d;

    cout << d + arr[0];

    return 0;
}