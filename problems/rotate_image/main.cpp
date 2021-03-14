#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int>> matrix{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    Solution sln;
    sln.rotate(matrix);
    for (auto vec : matrix) {
        for (auto element : vec) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
