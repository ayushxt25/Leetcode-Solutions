class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> freq(26, 0);
        int n = s.size(), m = p.size();

        if (m > n) return ans;

        for (char c : p) freq[c - 'a']++;

        int left = 0, count = m;

        for (int right = 0; right < n; right++) {
            if (freq[s[right] - 'a']-- > 0) count--;

            if (right - left + 1 > m) {
                if (++freq[s[left] - 'a'] > 0) count++;
                left++;
            }

            if (count == 0) ans.push_back(left);
        }

        return ans;
    }
};