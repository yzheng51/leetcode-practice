#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    int n = 10;
    Solution sln;
    auto res = sln.nthUglyNumber(n);
    std::cout << res << std::endl;
    return 0;
}
