class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> dp(n+1);

        for(int j = 0; j <= n; j++){
            dp[j] = j;
        }

        for(int i = 1; i <= m; i++){
            vector<int> ndp(n + 1);
            ndp[0] = i;

            for(int j = 1; j <= n; j++){
                if(word1[i - 1] == word2[j - 1]){
                    ndp[j] = dp[j - 1];
                } else {
                    ndp[j] = 1 + min({dp[j], ndp[j - 1], dp[j - 1]});
                }
            }
            dp = ndp;
        }

        return dp[n];
    }
};