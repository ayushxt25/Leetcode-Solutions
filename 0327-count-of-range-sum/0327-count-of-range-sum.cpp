class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> prefix(nums.size() + 1, 0);

        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        return mergeSort(prefix, 0, prefix.size(), lower, upper);
    }

    int mergeSort(vector<long long>& prefix, int left, int right, int lower, int upper) {
        if (right - left <= 1) return 0;

        int mid = left + (right - left) / 2;
        int count = mergeSort(prefix, left, mid, lower, upper) +
                    mergeSort(prefix, mid, right, lower, upper);

        int j = mid, k = mid;

        for (int i = left; i < mid; i++) {
            while (k < right && prefix[k] - prefix[i] < lower) k++;
            while (j < right && prefix[j] - prefix[i] <= upper) j++;
            count += j - k;
        }

        inplace_merge(prefix.begin() + left, prefix.begin() + mid, prefix.begin() + right);

        return count;
    }
};