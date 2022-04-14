class Solution {
public:
    // 寻找重复数
    int findDuplicate(vector<int>& nums) {
        // 通过 nums[nums[i]] 把数组转换成链表
        // 问题转化为 环形链表 找入口
        int n = nums.size(), f=0, s=0;
        while (1) {
            f=nums[nums[f]];
            s=nums[s];
            // 快慢指针步数: f=2s
            // 设链表头到入口的长度 a, 环（包含入口）的长度 b
            // 环相遇时, f 比 s 多走 n 个 环(都走过 a 步, 进入环后在环内绕圈)
            // 设 s 走了 x 步, 则 f 走 2x 步, 有 x%b == 2x %b
            // 即 (x-2x) % b == 0 所以 f 比 x 多走 n*b 步
            // f = 2s = s + nb , s = nb
            // 又所有走到入口的步数为 k=a+nb (n 绕圈数)
            // 当 s 走 a 步时必走到入口, 重新从 header 走 a 步即入口遇见 s
            if (s==f) {
                f=0;
                while (s!=f)
                    s=nums[s],f=nums[f];
                break;
            }
        }
        return f;
    }
};