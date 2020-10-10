#include <string>

class Solution {
public:
    int myAtoi(std::string str) {
        int ptr = 0;
        int n = str.size();
        int64_t res = 0;
        int flag = 1;
        while (str[ptr] == ' ') {
            ++ptr;
        }
        if (str[ptr] == '+') {
            ++ptr;
        } else if (str[ptr] == '-') {
            ++ptr;
            flag = -1;
        }
        while (ptr != n) {
            if (!std::isdigit(str[ptr])) {
                return int(flag * res);
            }
            res = res * 10 + str[ptr] - '0';
            if (flag * res >= INT_MAX) {
                return INT_MAX;
            }
            if (flag * res <= INT_MIN) {
                return INT_MIN;
            }
            ++ptr;
        }
        return int(flag * res);
    }
};
