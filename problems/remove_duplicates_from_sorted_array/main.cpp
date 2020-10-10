#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    std::vector<int> arr{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution sln;
    auto res = sln.removeDuplicates(arr);
    std::cout << res << std::endl;
    for (auto element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    return 0;
}
