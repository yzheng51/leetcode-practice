#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    int target = 9;
    vector<int> numbers{2, 7};
    Solution sln;
    auto res = sln.twoSum(numbers, target);
    for (auto element : res) {
        std::cout << element << std::endl;
    }
    return 0;
}
