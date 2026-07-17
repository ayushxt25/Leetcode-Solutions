class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (desiredTotal <= 0) return true;
        if (sum < desiredTotal) return false;

        unordered_map<int, bool> memo;
        return dfs(maxChoosableInteger, desiredTotal, 0, memo);
    }

    bool dfs(int n, int target, int mask, unordered_map<int, bool>& memo) {
        if (memo.count(mask)) return memo[mask];

        for (int i = 1; i <= n; i++) {
            int bit = 1 << (i - 1);

            if (!(mask & bit)) {
                if (i >= target || !dfs(n, target - i, mask | bit, memo)) {
                    return memo[mask] = true;
                }
            }
        }

        return memo[mask] = false;
    }
};