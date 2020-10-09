#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    std::string s = "cbbd";
    Solution sln;
    auto res = sln.longestPalindrome(s);
    std::cout << res << std::endl;
    return 0;
}
