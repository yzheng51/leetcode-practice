#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    std::vector<int> nums{3, 4, 5, 1, 2};
    Solution sln;
    auto res = sln.findMin(nums);
    std::cout << res << std::endl;
    return 0;
}
