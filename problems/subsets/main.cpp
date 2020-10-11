#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    vector<int> arr{1, 2, 3};
    Solution sln;
    auto res = sln.subsets(arr);
    for (auto vec : res) {
        for (auto item : vec) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
