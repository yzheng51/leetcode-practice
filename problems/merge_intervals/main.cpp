#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    Solution sln;
    auto res = sln.merge(intervals);
    for (auto interval : res) {
        std::cout << interval[0] << ", " << interval[1] << std::endl;
    }
    return 0;
}
