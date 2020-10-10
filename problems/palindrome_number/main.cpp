#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    int x = 121;
    Solution sln;
    auto res = sln.isPalindrome(x);
    std::cout << res << std::endl;
    return 0;
}
