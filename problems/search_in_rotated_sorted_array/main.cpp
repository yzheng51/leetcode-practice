#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    std::vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    Solution sln;
    auto res = sln.search(nums, 7);
    std::cout << res << std::endl;
    return 0;
}
