class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int xr = 0;

        for (int num : nums) {
            xr ^= num;
        }

        return xr == 0 || nums.size() % 2 == 0;
    }
};