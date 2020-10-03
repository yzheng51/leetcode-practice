#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    int target = 9;
    std::vector<int> arr{2, 7, 11, 15};
    Solution sln;
    auto res = sln.twoSum(arr, target);
    std::cout << res[0] << ", " << res[1] << std::endl;
    return 0;
}
