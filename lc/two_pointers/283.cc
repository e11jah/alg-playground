#include <vector>
using namespace std;
class Solution {
public:
    // 保持顺序用快慢针
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return;
        int s = 0;
        for (int f = 0; f < n; f++) {
            if (nums[f]!=0)
                nums[s++]=nums[f];
        }
        while (s < n)
            nums[s++]=0;
    }
};