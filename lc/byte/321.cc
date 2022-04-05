#include <vector>
using namespace std;
// 拼接最大数 分治 单调栈
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int a = nums1.size(), b = nums2.size();
        vector<int> s1, s2, t,ans(k,0);
        // 枚举 n1 的所有 长度 i 的最大字典序序列
        // 合并两个数组后得到的最大字典序序列必然由两个数组的最大字典序子序列构成
        for (int i = max(0,k-b); i <= min(a,k); i++) {// i <= min(a,k) 最长可以为全序列
            s1.clear(),s2.clear(),t.clear();
            getMaxSub(nums1,s1,i);
            getMaxSub(nums2,s2,k-i);
            auto it1 = s1.begin(), it2 = s2.begin();
            while (it1 != s1.end() || it2 != s2.end())
                // 推入字典序大的
                t.push_back(lexicographical_compare(it1, s1.end(), it2, s2.end())?*it2++:*it1++);
            ans = lexicographical_compare(ans.begin(), ans.end(), t.begin(),t.end())?t:ans;
        }
        return ans;
    }

    void getMaxSub(vector<int> & a, vector<int> & s, int len) {
        int n = a.size(), op = n-len;
        if (len >= n) {
            s.insert(s.begin(), a.begin(), a.end());
            return;
        }
        for (int i = 0; i < n; i++) {
            while (!s.empty() && a[i]>s.back()&&op)
                s.pop_back(),op--;
            s.push_back(a[i]);
        }
        // 处理 op 不为 0
        s.resize(len);
    }
};