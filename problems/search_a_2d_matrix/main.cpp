#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    // std::vector<std::vector<int>> matrix {{1}, {3}};
    int target = 3;
    Solution sln;
    auto res = sln.searchMatrix(matrix, target);
    std::cout << res << std::endl;
    return 0;
}
