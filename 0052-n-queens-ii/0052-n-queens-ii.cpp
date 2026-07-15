class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        backtrack(0, n, 0, 0, 0, ans);
        return ans;
    }

    void backtrack(int row, int n, int cols, int diag1, int diag2, int& ans) {
        if (row == n) {
            ans++;
            return;
        }

        int available = ((1 << n) - 1) & ~(cols | diag1 | diag2);

        while (available) {
            int bit = available & -available;
            available -= bit;
            backtrack(row + 1, n, cols | bit, (diag1 | bit) << 1, (diag2 | bit) >> 1, ans);
        }
    }
};