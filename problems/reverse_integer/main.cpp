#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    int x = 123;
    Solution sln;
    auto res = sln.reverse(x);
    std::cout << res << std::endl;
    return 0;
}
