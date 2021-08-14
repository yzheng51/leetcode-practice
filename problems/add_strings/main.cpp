#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    std::string num1 = "11";
    std::string num2 = "123";
    Solution sln;
    auto res = sln.addStrings(num1, num2);
    std::cout << res << std::endl;

    return 0;
}
