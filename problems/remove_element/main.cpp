#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    std::vector<int> arr{0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    Solution sln;
    auto res = sln.removeElement(arr, val);
    std::cout << res << std::endl;
    for (auto element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    return 0;
}
