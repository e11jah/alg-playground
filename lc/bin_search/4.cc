#include <vector>
using namespace std;
class Solution {
    int n,m;
public:
    // 两个有序数组找第 k 小（二分）
    int findKth(vector<int>& nums1, vector<int> & nums2, int k) {
        // 双数组二分
        int l1=0, l2=0, r1, r2;
        while (1) {
            if (l1==n)
                return nums2[l2+k-1];
            if (l2==m)
                return nums1[l1+k-1];
            // 第 k 个从 1 数起
            if (k==1)
                return min(nums1[l1], nums2[l2]);
            // 移动 k/2 
            r1=min(l1+k/2-1,n-1),r2=min(l2+k/2-1,m-1);

            // 比较完减去差值
            if (nums1[r1]<nums2[r2]) {
                k-=(r1-l1)+1, l1=r1+1;
            } else {
                k-=(r2-l2)+1,l2=r2+1;
            }

        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size(), m = nums2.size();

        if ((n+m)&1) {
            // 中位从 1 数起
            return findKth(nums1, nums2, (n+m+1)/2);
        } else {
            int l = findKth(nums1, nums2, (n+m+1)/2);
            // 偶数找中间两个数
            int r = findKth(nums1, nums2, (n+m+2)/2);
            return (l+r)/2.0;
        }
    }
};