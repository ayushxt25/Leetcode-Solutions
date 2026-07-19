class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        const int MOD = 1e9 + 7;
        int maxVal = *max_element(instructions.begin(), instructions.end());
        vector<int> bit(maxVal + 2, 0);
        long long ans = 0;

        for (int i = 0; i < instructions.size(); i++) {
            int x = instructions[i];
            int less = query(bit, x - 1);
            int greater = i - query(bit, x);
            ans = (ans + min(less, greater)) % MOD;
            update(bit, x, 1);
        }

        return ans;
    }

    void update(vector<int>& bit, int idx, int val) {
        while (idx < bit.size()) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(vector<int>& bit, int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};