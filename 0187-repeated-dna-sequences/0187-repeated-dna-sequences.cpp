class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<char, int> mp{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        unordered_set<int> seen, repeated;
        vector<string> ans;
        int n = s.size(), mask = (1 << 20) - 1, hash = 0;

        for (int i = 0; i < n; i++) {
            hash = ((hash << 2) | mp[s[i]]) & mask;

            if (i >= 9) {
                if (seen.count(hash) && !repeated.count(hash)) {
                    ans.push_back(s.substr(i - 9, 10));
                    repeated.insert(hash);
                }
                seen.insert(hash);
            }
        }

        return ans;
    }
};