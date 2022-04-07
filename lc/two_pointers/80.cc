#include <vector>
using namespace std;
class Solution {
public:
    //  (快慢指针) 原地 删除重复出现的元素，使每个元素 最多出现两次 ，返回删除后数组的新长度。
    int removeDuplicates(vector<int>& nums) {
        int s=0,k=2,n=nums.size();
        if (n < 2)
            return n;
        // iter fast pointer
        for (int f = 0; f < n; f++) {
            if (s < k || nums[s-k]!=nums[f])
                nums[s++]=nums[f];
        }
        // s 最后的位置即终点
        return s;
    }
};