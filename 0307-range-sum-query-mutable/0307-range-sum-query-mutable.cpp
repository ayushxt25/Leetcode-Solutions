class NumArray {
private:
    vector<int> bit;
    vector<int> nums;
    int n;

    void add(int idx, int delta) {
        idx++;
        while (idx <= n) {
            bit[idx] += delta;
            idx += idx & -idx;
        }
    }

    int prefixSum(int idx) {
        idx++;
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        bit.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            add(i, nums[i]);
        }
    }
    
    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;
        add(index, delta);
    }
    
    int sumRange(int left, int right) {
        return prefixSum(right) - (left == 0 ? 0 : prefixSum(left - 1));
    }
};