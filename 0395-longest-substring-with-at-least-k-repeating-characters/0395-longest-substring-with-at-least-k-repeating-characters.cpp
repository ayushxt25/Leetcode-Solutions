class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;

        for (int target = 1; target <= 26; target++) {
            vector<int> freq(26, 0);
            int left = 0, right = 0;
            int unique = 0, countAtLeastK = 0;

            while (right < s.size()) {
                if (unique <= target) {
                    int idx = s[right] - 'a';
                    if (freq[idx] == 0) unique++;
                    freq[idx]++;
                    if (freq[idx] == k) countAtLeastK++;
                    right++;
                } else {
                    int idx = s[left] - 'a';
                    if (freq[idx] == k) countAtLeastK--;
                    freq[idx]--;
                    if (freq[idx] == 0) unique--;
                    left++;
                }

                if (unique == target && unique == countAtLeastK) {
                    ans = max(ans, right - left);
                }
            }
        }

        return ans;
    }
};