#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    std::string s = "()[]{}";
    Solution sln;
    auto res = sln.isValid(s);
    std::cout << res << std::endl;
    return 0;
}
