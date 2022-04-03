#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    /**
     * dp 解码
     * @param nums string字符串 数字串
     * @return int整型
     */
    int solve(string nums) {
        // write code here
        // f[i]=f[i-1]+f[i-2]
        int n = nums.size(),t2,t1;
        if (n<1||(n==1&&nums=="0"))
            return 0;
        vector<int> f(n+1,0);
        f[1]=1;
        for (int i = 2; i <= n; i++) {
            t2=stoi(nums.substr(i-2,2));
            t1=nums[i-1]-'0';
            
            if (t1>0)
                f[i]=f[i-1];
            // 10, 20 排除, '07' 排除
            if (nums[i-2]!='0'&&t2>0&&t2<27)
                f[i]+=i-2>0?f[i-2]:1;

        }
        return f[n];
    }
};