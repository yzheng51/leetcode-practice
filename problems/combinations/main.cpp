#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    int n = 4;
    int k = 2;
    Solution sln;
    auto res = sln.combine(n, k);
    for (auto vec : res) {
        for (auto item : vec) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
