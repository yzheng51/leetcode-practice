#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    std::string s = "  -0012a42";
    Solution sln;
    auto res = sln.myAtoi(s);
    std::cout << res << std::endl;
    return 0;
}
