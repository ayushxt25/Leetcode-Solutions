class Solution {
public:
    unordered_set<string> st;
    unordered_map<int, vector<string>> memo;

    vector<string> dfs(string &s, int idx) {
        if (memo.count(idx)) return memo[idx];

        vector<string> res;
        if (idx == s.size()) {
            res.push_back("");
            return memo[idx] = res;
        }

        string cur;
        for (int i = idx; i < s.size(); i++) {
            cur.push_back(s[i]);
            if (st.count(cur)) {
                vector<string> next = dfs(s, i + 1);
                for (auto &n : next) {
                    res.push_back(cur + (n.empty() ? "" : " " + n));
                }
            }
        }

        return memo[idx] = res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        st = unordered_set<string>(wordDict.begin(), wordDict.end());
        memo.clear();
        return dfs(s, 0);
    }
};