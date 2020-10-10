#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    vector<vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    Solution sln;
    auto res = sln.minPathSum(grid);
    std::cout << res << std::endl;
    return 0;
}
