#include <vector>
using namespace std;
class Solution {
public:
    /**
     * 缺失的第一个正数
     * 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
     * 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
     */
    int firstMissingPositive(vector<int>& nums) {
        // 原地哈希 num[i] = i+1
        // 合法元素范围 1~n
        int n = nums.size();
        // 交换后部分元素被跳过，时间复杂度 O(n)
        for (int i = 0; i < n; i++) {
            while (nums[i]!=i+1) {
                if (nums[i]<1||nums[i]>n||nums[i]==i+1)
                    break;
                int idx = nums[i]-1;
                // 防止环
                if (nums[idx]==idx+1)
                    break;
                nums[i]=nums[idx];
                nums[idx]=idx+1;
            }
        }
        for (int i = 0; i < n; i++)
            if (nums[i]!=i+1)
                return i+1;
        return n+1;
    }
    int solve1(vector<int>& nums) {
        int n=nums.size(), t;
        for (int i = 0; i < n;i++) {
            if (nums[i] < 1 || nums[i] > n)
                nums[i]=0;
        }

        for (int i = 0; i < n; i++) {
            t = nums[i]%(n+1);
            if (t==0)
                continue;
            nums[t-1]+=n+1;
            nums[i]-=t;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i]<n)
                return i+1;
        }

        return n+1;
    }
};