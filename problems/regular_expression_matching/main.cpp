#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    std::string s = "aab";
    std::string p = "c*a*b";
    Solution sln;
    auto res = sln.isMatch(s, p);
    std::cout << res;
    return 0;
}
