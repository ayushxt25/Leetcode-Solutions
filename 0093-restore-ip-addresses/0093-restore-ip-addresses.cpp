class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string curr;

        function<void(int, int)> backtrack = [&](int idx, int parts) {
            if (parts == 4) {
                if (idx == s.size()) {
                    curr.pop_back();
                    ans.push_back(curr);
                    curr.push_back('.');
                }
                return;
            }

            for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {
                string part = s.substr(idx, len);

                if (part.size() > 1 && part[0] == '0') break;
                if (stoi(part) > 255) break;

                int oldSize = curr.size();
                curr += part + ".";
                backtrack(idx + len, parts + 1);
                curr.resize(oldSize);
            }
        };

        backtrack(0, 0);
        return ans;
    }
};