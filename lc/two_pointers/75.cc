#include <vector>

using namespace std;
class Solution {
public:
    // 红色、白色放两端=双端双指针
    void sortColors(vector<int>& nums) {
        int c0=0, n=nums.size(), c2=n-1,i=0;
        while (i<=c2) {
            if (nums[i]==0&&i!=c0)
                swap(nums[i], nums[c0]),c0++;
            else if (nums[i]==2&&i!=c2)
                swap(nums[i],nums[c2]),c2--;
            else
                i++;
        }
    }
};