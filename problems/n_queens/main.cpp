#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    int n = 4;
    Solution sln;
    auto res = sln.solveNQueens(n);
    for (auto col : res) {
        for (auto row : col) {
            std::cout << row << std::endl;
        }
    }
    return 0;
}
