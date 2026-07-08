class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> odd(n), even(n);
        map<int, int> mp;

        odd[n - 1] = even[n - 1] = true;
        mp[arr[n - 1]] = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            auto hi = mp.lower_bound(arr[i]);
            if (hi != mp.end()) odd[i] = even[hi->second];

            auto lo = mp.upper_bound(arr[i]);
            if (lo != mp.begin()) {
                --lo;
                even[i] = odd[lo->second];
            }

            mp[arr[i]] = i;
        }

        return count(odd.begin(), odd.end(), true);
    }
};