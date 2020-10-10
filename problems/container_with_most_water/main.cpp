#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    std::vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution sln;
    auto res = sln.maxArea(height);
    std::cout << res << std::endl;
    return 0;
}
