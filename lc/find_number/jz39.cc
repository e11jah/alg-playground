class Solution {
public:
    // 数组中超过一半的数字
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        // 侯选法
        int cnt=0, cond;
        for (int x : numbers) {
            if (cnt<=0) cond=x,cnt++;
            else if (cond==x) cnt++;
            // 不同则消去
            else cnt--;
        }
        cnt=0;
        for (int x : numbers)
            if (x==cond) cnt++;
        if (cnt>=numbers.size()/2) return cond;
        return 0;
    }
};