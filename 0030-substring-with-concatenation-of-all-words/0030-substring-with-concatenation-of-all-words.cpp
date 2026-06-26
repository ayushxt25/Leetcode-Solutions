class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;

        int n = s.size();
        int m = words.size();
        int len = words[0].size();
        int total = m * len;

        unordered_map<string, int> freq;
        for (auto &w : words) freq[w]++;

        for (int i = 0; i < len; i++) {
            unordered_map<string, int> window;
            int left = i, count = 0;

            for (int j = i; j + len <= n; j += len) {
                string word = s.substr(j, len);

                if (freq.count(word)) {
                    window[word]++;
                    count++;

                    while (window[word] > freq[word]) {
                        string leftWord = s.substr(left, len);
                        window[leftWord]--;
                        left += len;
                        count--;
                    }

                    if (count == m) {
                        res.push_back(left);
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = j + len;
                }
            }
        }

        return res;
    }
};