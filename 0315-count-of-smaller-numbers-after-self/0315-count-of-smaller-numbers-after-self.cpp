class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n), indexes(n);

        for (int i = 0; i < n; i++) indexes[i] = i;

        mergeSort(nums, indexes, ans, 0, n - 1);
        return ans;
    }

    void mergeSort(vector<int>& nums, vector<int>& indexes, vector<int>& ans, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(nums, indexes, ans, left, mid);
        mergeSort(nums, indexes, ans, mid + 1, right);

        vector<int> temp;
        int i = left, j = mid + 1;
        int smallerRight = 0;

        while (i <= mid && j <= right) {
            if (nums[indexes[j]] < nums[indexes[i]]) {
                temp.push_back(indexes[j++]);
                smallerRight++;
            } else {
                ans[indexes[i]] += smallerRight;
                temp.push_back(indexes[i++]);
            }
        }

        while (i <= mid) {
            ans[indexes[i]] += smallerRight;
            temp.push_back(indexes[i++]);
        }

        while (j <= right) {
            temp.push_back(indexes[j++]);
        }

        for (int k = left; k <= right; k++) {
            indexes[k] = temp[k - left];
        }
    }
};