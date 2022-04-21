#define FOR(i,l,r) for(int i = l; i <=r; i++)
#define RFOR(i,r,l) for (int i = r; i >= l; i--)
typedef unsigned long long ull;

class Solution {

public:
    // 查找给定哈希值的子串
    // 给定字符串和哈希方法, 找给定长度的相同哈希值的子串
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = s.size(), idx=0;

        // 逆序计算哈希(最后一段)
        ull x=0, p=1;
        // 算出 p^k-1 次
        RFOR(i,n-1,n-k+1)
             p=p*power%modulo,x=power*(x+s[i]-96)%modulo;
        // 按题目要求, 需要反向滑动窗口计算 hash 比较
        RFOR(i,n-k,0) {
            // 加头
            x=(x+s[i]-96)%modulo;
            if (x==hashValue)
                idx=i;
            // 去尾
            // 提前 + MOD 防止负数
            x=power*(x+modulo-(s[i+k-1]-96)*p%modulo)%modulo;
            // 按照题目公式 p 保持为 p^k-1 
        }
        return s.substr(idx,k);
    }
};