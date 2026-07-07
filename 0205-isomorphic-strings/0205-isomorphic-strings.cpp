class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> mapS(256, -1), mapT(256, -1);

        for (int i = 0; i < s.size(); i++) {
            if (mapS[s[i]] != mapT[t[i]]) return false;
            mapS[s[i]] = i;
            mapT[t[i]] = i;
        }

        return true;
    }
};