class Solution {
public:
    int nextIndex(vector<int>& nums, int i) {
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;

            int slow = i, fast = i;
            bool dir = nums[i] > 0;

            while (true) {
                int nextSlow = nextIndex(nums, slow);
                int nextFast = nextIndex(nums, fast);
                int nextFast2 = nextIndex(nums, nextFast);

                if ((nums[nextSlow] > 0) != dir ||
                    (nums[nextFast] > 0) != dir ||
                    (nums[nextFast2] > 0) != dir)
                    break;

                slow = nextSlow;
                fast = nextFast2;

                if (slow == fast) {
                    if (slow == nextIndex(nums, slow)) break;
                    return true;
                }
            }

            int cur = i;
            while (nums[cur] != 0 && (nums[cur] > 0) == dir) {
                int next = nextIndex(nums, cur);
                nums[cur] = 0;
                cur = next;
            }
        }

        return false;
    }
};