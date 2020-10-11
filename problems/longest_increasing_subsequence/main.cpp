#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    std::vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    Solution sln;
    auto res = sln.lengthOfLIS(nums);
    std::cout << res << std::endl;
    return 0;
}
