#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    std::string digits = "23";
    Solution sln;
    auto res = sln.letterCombinations(digits);
    for (auto num : res) {
        std::cout << num << " ";
    }
    return 0;
}
