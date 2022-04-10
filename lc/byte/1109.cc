#include <vector>

using namespace std;
class Solution {

public:
    // bookings 记录 [f, l, s], 表示 f 到 s 的航班预订了 s 个座位
    // 求每个航班（1~n）预订的座位总数
    /*
    给一组日志文件，包含用户id，登陆时间，登出时间，假定时间范围一天之内，
    求出一天之内在线用户数量的峰值，并给出时间区间（多个相等区间都输出，可以假设登录登出时间为整数）
    1. 维护差分数组，求24*60*60的用户数, 取最大值为峰值, 用户数为最大值的区间是峰值区间
    */
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
         vector<int> d(n+2);
         // 差分数组
         for (vector<int> v : bookings) {
             d[v[0]]+=v[2], d[v[1]+1]-=v[2];
         }
         int prev=0;
         vector<int>ans(n);
         for (int i = 1; i <=n; i++) 
            prev+=d[i],ans[i-1]=prev;
        return ans;
    }
    void solve2(vector<vector<int>>& bookings,int n) {
        vector<int> ans(n);
         for (vector<int> v : bookings) {
             ans[v[0]-1]+=v[2];
             if (v[1]<n)
                ans[v[1]]-=v[2];
         }


         for (int i = 1; i <n; i++) 
            ans[i]+=ans[i-1];
    }
};