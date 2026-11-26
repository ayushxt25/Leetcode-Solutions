class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> row(26);

        for (char c : string("qwertyuiop")) row[c - 'a'] = 1;
        for (char c : string("asdfghjkl")) row[c - 'a'] = 2;
        for (char c : string("zxcvbnm")) row[c - 'a'] = 3;

        vector<string> ans;

        for (string& word : words) {
            int r = row[tolower(word[0]) - 'a'];
            bool ok = true;

            for (char c : word) {
                if (row[tolower(c) - 'a'] != r) {
                    ok = false;
                    break;
                }
            }

            if (ok) ans.push_back(word);
        }

        return ans;
    }
};