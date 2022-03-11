#include <vector>
#include <iostream>

using namespace std;

class Solution2 {
public:
    int n, hn;
    vector<int> houses_, heaters_;

    bool check(long long mid) {
        int p = 0;
        for (auto v:houses_) {
            while (v < heaters_[p] - mid || v > heaters_[p] + mid) {
                if (p == hn - 1) return false;
                p++;
            }
        }
        return true;
    }

    int findRadius(vector<int> &houses, vector<int> &heaters) {

        n = houses.size(), hn = heaters.size();
        // 保证有序
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        houses_ = houses, heaters_ = heaters;
        long long l = 0, r = 1e9, mid, res = r;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (check(mid))
                r = mid - 1, res = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

class Solution1 {
public:
    // 最佳买卖股票时机含冷冻期
    int maxProfit309(vector<int> &prices) {
        int n = prices.size(), a, b;
        vector<vector<int>> dp(3, vector<int>(n));
        // 0 不持有, 1 持有，2 冷冻
        dp[1][0] = -prices[0];// dp[2][0] = -prices[0];
        for (int i = 1; i < n; i++) {
            // 不持有或冷冻接触
            dp[0][i] = max(dp[0][i - 1], dp[2][i - 1]);
            // 非冷冻（冷冻结束）买入或继续持有
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] - prices[i]);
            // 卖出进入冷冻
            dp[2][i] = dp[1][i - 1] + prices[i];
        }
        // 刚刚卖出（进入冷冻）或在最后一天之前卖出
        return max(dp[2][n - 1], dp[0][n - 1]);
    }

    // 买卖股票的最佳时机含手续费
    int maxProfit714(vector<int> &prices, int fee) {
        int n = prices.size(), a, b;
        // I 第 i 天持有股份的最大利润
        // O 第 i 天不持有股份的最大利润
        vector<int> O(n), I(n);
        I[0] = -prices[0];
        for (int i = 1; i < n; i++) {
            a = O[i - 1] - prices[i], b = I[i - 1] + prices[i] - fee;
            // I[i] 由 O[i-1] 转移
            I[i] = I[i - 1] > a ? I[i - 1] : a;
            // O[i] 由 I[i-1] 转移
            O[i] = b > O[i - 1] ? b : O[i - 1];
        }
        return O[n - 1];
    }
};


class Solution3 {
    vector<int> d;
public:
    bool check(int day) {
        int pre = 0;
        for (int i = 1; i <= day; i++)
            pre += d[i];
        return pre > 0;
    }

    int eatenApples(vector<int> &apples, vector<int> &days) {
        int n = apples.size(), t, ans = 0;
        d = vector<int>(n + 1);
        int i = 1;
        for (; i <= n; i++) {
            d[i] += apples[i - 1];
            t = i + days[i - 1];

            if (t >= d.size())
                d.insert(d.end(), t + 1, 0);

            d[t] -= apples[i - 1];

            if (check(i)) {
                d[i]--, d[t]++;
                ans++;
            }
        }
        while (check(i)) {
            d[i]--, ans++, i++;
        }

        return ans;
    }
};

class Solution55 {
public:
    int countQuadruplets(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        vector<int> sum(n + 1);
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + nums[i - 1];

        for (int i = 3; i < n; i++) {
            for (int l = 0; l + 2 < i; l++)
                if (sum[i] - sum[l] == nums[i])
                    ans++;
        }
        return ans;
    }
};


int contain(const string &a, const string &b, int r) {
    if (a.size() > b.size() - r)
        return -1;
    for (char j : a)
        if (r >= b.size() || b[r++] != j)
            return -1;
    return r;
}

class Solution {
    int n;
    string data, ar;
public:
    void add(int l, int m, int r) {
        int len = max(m-l, r-m), t = 0;
        ar.clear();
        for (int i = 1; i <= len; i++) {

            if (m-i >= l)
                t += (data[m-i] - '0');
            if (r-i >= m)
                t += (data[r-i] - '0');


            ar.push_back('0'+(t%10));
            t /= 10;
        }
        if (t)
            ar.push_back('0'+t);
        reverse(ar.begin(), ar.end());
    }
    int contain(const string & a, int r) {
        if (a.size() > n-r)
            return -1;
        for (char j : a)
            if (r >= n || data[r++] != j)
                return -1;
        return r;
    }

    bool dfs(int l, int m, int r) {
        if (r == n)
            return true;
        add(l, m, r);
        int next = contain(ar, r);

        if (next == -1)
            return false;

        return dfs(m, r, next);
    }

    bool isAdditiveNumber(string num) {
        data = num;
        n = num.size();
        for (int m = 1; m < n; m++)
            for (int r = m+1; r < n; r++)
                if (dfs(0, m, r))
                    return true;

        return false;
    }
};

int main() {
    vector<vector<int>> tt = {
            {1, 1, 1, 3, 5},
            {1, 2, 3, 6},
            {3, 3, 6, 4, 5},
    };
    int a = -3, b = 7;
    cout << (b + (a % b)) % b << endl;


    auto s = new Solution;
//    cout << tt.size() << endl;
    for (auto &i : tt) {
//        auto got = s->findAllConcatenatedWordsInADict(i);
//        for (const string& str : got)
//            cout << str << " ";
//        cout << s->countQuadruplets(i)<< endl;
//        cout << s->maxProfit(i.first, i.second) << endl;
    }

    s->isAdditiveNumber("199001200");



}



