#include <iostream>
#include <vector>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    std::vector<int> nums1{1, 2};
    std::vector<int> nums2{3, 4};
    Solution sln;
    auto res = sln.findMedianSortedArrays(nums1, nums2);
    std::cout << res << std::endl;
    return 0;
}
