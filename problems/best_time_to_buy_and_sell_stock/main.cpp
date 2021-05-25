#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    std::vector<int> prices { 7, 1, 5, 3, 6, 4 };
    Solution sln;
    auto res = sln.maxProfit(prices);
    std::cout << res << std::endl;

    return 0;
}
