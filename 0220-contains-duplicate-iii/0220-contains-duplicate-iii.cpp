class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_map<long long, long long> buckets;
        long long width = (long long)valueDiff + 1;

        for (int i = 0; i < nums.size(); i++) {
            long long num = nums[i];
            long long id = getBucketId(num, width);

            if (buckets.count(id)) return true;
            if (buckets.count(id - 1) && abs(num - buckets[id - 1]) < width) return true;
            if (buckets.count(id + 1) && abs(num - buckets[id + 1]) < width) return true;

            buckets[id] = num;

            if (i >= indexDiff) {
                buckets.erase(getBucketId(nums[i - indexDiff], width));
            }
        }

        return false;
    }

    long long getBucketId(long long num, long long width) {
        return num >= 0 ? num / width : ((num + 1) / width) - 1;
    }
};