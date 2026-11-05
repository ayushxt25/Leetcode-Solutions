class Solution {
    unordered_map<string, vector<int>> memo;

public:
    vector<int> diffWaysToCompute(string expression) {
        if (memo.count(expression)) return memo[expression];

        vector<int> res;

        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];

            if (c == '+' || c == '-' || c == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                for (int a : left) {
                    for (int b : right) {
                        if (c == '+') res.push_back(a + b);
                        else if (c == '-') res.push_back(a - b);
                        else res.push_back(a * b);
                    }
                }
            }
        }

        if (res.empty())
            res.push_back(stoi(expression));

        return memo[expression] = res;
    }
};