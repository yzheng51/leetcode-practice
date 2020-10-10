#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    double x = 0.44;
    int n = 10;
    Solution sln;
    auto res = sln.myPow(x, n);
    std::cout << res << std::endl;
    return 0;
}
