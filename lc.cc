#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> l;
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(l.begin(), l.end(), nums[i]);
            // 若找不到比 i 大的元素，放入序列
            if (it == l.end())
                l.push_back(nums[i]);
            else
                // 否则修改第一个比 i 大的元素为 i （后续元素与 i 比较，同时保留前面的长度）
                *it = nums[i];

        }
        return l.size();
    }
};

int main() {
    vector<int> tt = {10,9,2,5,3,7,101,18};
    auto s = new Solution;
    cout << s->lengthOfLIS(tt);
}



