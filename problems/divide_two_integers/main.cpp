#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    int dividend = -2147483648;
    int divisor = 1;
    Solution sln;
    auto res = sln.divide(dividend, divisor);
    std::cout << res << std::endl;
    return 0;
}
