#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return INT_MAX;
        }
        if (divisor == 1) {
            return dividend;  // for INT_MIN / 1
        }
        if (divisor == -1) {
            return dividend == INT_MIN ? INT_MAX : -dividend;  // for INT_MIN / -1
        }

        if (divisor == INT_MIN) {
            return dividend == INT_MIN;  // for any / INT_MIN
        }
        int b = abs(divisor);
        int a = (dividend == INT_MIN) ? abs(dividend + b) : abs(dividend);
        int res = dividend == INT_MIN;
        while (a >= b) {
            int t = b;
            int m = 1;
            while (t << 1 > 0 && t << 1 <= a) {
                t <<= 1;
                m <<= 1;
            }
            a -= t;
            res += m;
        }
        return (dividend > 0 ^ divisor > 0) ? -res : res;
    }
};
