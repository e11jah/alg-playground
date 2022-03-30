// n 皇后
class Solution {
    int a[10],m,c=0;
public:
    bool check(int row, int col) {
        for (int i = 1; i < row;i++) {
            if (a[i]==col) return false;
            // 和相等
            if (row+col==i+a[i]) return false;
            // 差相等
            if (row-col==i-a[i]) return false;
        }
        return true;
    }
    void dfs(int row) {
        if (row>m) {
            c++;
            return;
        }
        for (int i= 1; i <=m; i++) {
            if (check(row,i)) {
                a[row]=i;
                dfs(row+1);
                a[row]=0;
            }
        }
    }
    
    /**
     * 
     * @param n int整型 the n
     * @return int整型
     */
    int Nqueen(int n) {
        // write code here
        if (n<2)
            return 1;
        m=n;
        dfs(1);
        return c;
    }
};