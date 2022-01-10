class Solution {
    int n;
    string data, ar;
public:
    void add(int l, int m, int r) {
        int len = max(m - l, r - m), t = 0;
        ar.clear();
        for (int i = 1; i <= len; i++) {
            if (m - i >= l)
                t += (data[m - i] - '0');
            if (r - i >= m)
                t += (data[r - i] - '0');

            ar.push_back('0' + (t % 10));
            t /= 10;
        }
        if (t)
            ar.push_back('0' + t);
        reverse(ar.begin(), ar.end());
    }

    int contain(const string &a, int r) {
        if (a.size() > n - r)
            return -1;
        for (char j : a)
            if (r >= n || data[r++] != j)
                return -1;
        return r;
    }

    bool dfs(int l, int m, int r) {
        if (r == n)
            return true;

        // 前导 0
        if ((data[l] == '0' && m - l > 1) || (data[m] == '0' && r - m > 1))
            return false;
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
            for (int r = m + 1; r < n; r++)
                if (dfs(0, m, r))
                    return true;

        return false;
    }
};



