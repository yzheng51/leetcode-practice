#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    vector<vector<int>> matrix = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}};
    Solution sln;
    sln.setZeroes(matrix);
    for (auto vec : matrix) {
        for (auto item : vec) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
