#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    int x = 9;
    Solution sln;
    auto res = sln.mySqrt(x);
    std::cout << res << std::endl;
    return 0;
}
