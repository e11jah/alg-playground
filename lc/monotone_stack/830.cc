#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, t;
    cin >> n;
    vector<int> v;
    
    for (int i = 0; i <n; i++) {
        cin >> t;
        // ιε’εΊε
        
        while (!v.empty()&&v.back()>=t) 
            v.pop_back();
        
        cout << (v.empty()?-1:v.back()) << ' ';
        
        v.push_back(t);
        
    }
}

int main() {
    solve();
    return 0;
}