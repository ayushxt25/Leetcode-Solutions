class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<long long> lo, hi;

        auto rebalance = [&]() {
            while (lo.size() > hi.size() + 1) {
                hi.insert(*prev(lo.end()));
                lo.erase(prev(lo.end()));
            }

            while (lo.size() < hi.size()) {
                lo.insert(*hi.begin());
                hi.erase(hi.begin());
            }
        };

        auto add = [&](long long x) {
            if (lo.empty() || x <= *prev(lo.end()))
                lo.insert(x);
            else
                hi.insert(x);

            rebalance();
        };

        auto remove = [&](long long x) {
            auto it = lo.find(x);

            if (it != lo.end())
                lo.erase(it);
            else
                hi.erase(hi.find(x));

            rebalance();
        };

        vector<double> ans;

        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]);

            if (i >= k)
                remove(nums[i - k]);

            if (i >= k - 1) {
                if (k & 1)
                    ans.push_back((double)*prev(lo.end()));
                else
                    ans.push_back((*prev(lo.end()) + *hi.begin()) / 2.0);
            }
        }

        return ans;
    }
};