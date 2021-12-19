#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    int lis(vector<int> v) {
        vector<int> l;
        for (int e : v) {
            // uppper_bound >= x 的第一个
            // lower_bound > x 的第一个
            auto it = upper_bound(l.begin(), l.end(), e);
            if (it == l.end())
                l.push_back(e);
            else
                // 找到 >= e 的第一个元素，对其修改（以便将后续元素计算进此序列中）
                *it = e;
        }
        return l.size();
    }
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size(), ans = 0;
        // arr[i-k] <= arr[i] 间隔为 k 的子序列
        vector<int> karr;
        for (int i = 0; i < k; i++) {
            karr.clear();
            for (int j = i; j < n; j += k)
                karr.push_back(arr[j]);

            ans += lis(karr);
        }
        return n - ans;
    }
};

int main() {
    vector<int> tt = {10,9,2,5,3,7,101,18};
    auto s = new Solution;
//    cout << s->lengthOfLIS(tt);
}



