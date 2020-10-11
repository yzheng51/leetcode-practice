#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    int num = 8;
    Solution sln;
    auto res = sln;
    std::cout << sln.isUgly(num) << std::endl;
    return 0;
}
