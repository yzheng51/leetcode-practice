#include <algorithm>
#include <string>

class Solution {
public:
    std::string addStrings(std::string num1, std::string num2) {
        int n1 = num1.size() - 1;
        int n2 = num2.size() - 1;
        int c = 0;

        std::string res;

        while (n1 >= 0 || n2 >= 0 || c) {
            int s = 0;
            if (n1 >= 0) {
                s += num1[n1--] - '0';
            }
            if (n2 >= 0) {
                s += num2[n2--] - '0';
            }
            s += c;
            c = s / 10;
            s = s % 10;

            res.push_back(s + '0');
        }
        std::reverse(res.begin(), res.end());

        return res;
    }
};
