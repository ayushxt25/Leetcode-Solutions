class Solution {
public:
    int calculate(string s) {
        long long num = 0, last = 0, result = 0;
        char op = '+';

        for (int i = 0; i <= s.size(); i++) {
            char c = (i < s.size()) ? s[i] : '+';

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            if ((!isdigit(c) && c != ' ') || i == s.size()) {
                if (op == '+') {
                    result += last;
                    last = num;
                } else if (op == '-') {
                    result += last;
                    last = -num;
                } else if (op == '*') {
                    last *= num;
                } else if (op == '/') {
                    last /= num;
                }

                op = c;
                num = 0;
            }
        }

        return result + last;
    }
};