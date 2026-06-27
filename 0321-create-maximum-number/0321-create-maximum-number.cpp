class Solution {
public:
    vector<int> maxArray(vector<int>& nums, int k) {
        vector<int> st;
        int drop = nums.size() - k;

        for (int x : nums) {
            while (!st.empty() && drop > 0 && st.back() < x) {
                st.pop_back();
                drop--;
            }
            st.push_back(x);
        }

        st.resize(k);
        return st;
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> res;
        int i = 0, j = 0;

        while (i < a.size() || j < b.size()) {
            if (lexicographical_compare(a.begin() + i, a.end(), b.begin() + j, b.end()))
                res.push_back(b[j++]);
            else
                res.push_back(a[i++]);
        }

        return res;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;

        int m = nums1.size(), n = nums2.size();

        for (int i = max(0, k - n); i <= min(k, m); i++) {
            vector<int> a = maxArray(nums1, i);
            vector<int> b = maxArray(nums2, k - i);
            vector<int> cur = merge(a, b);

            if (cur > ans) ans = cur;
        }

        return ans;
    }
};