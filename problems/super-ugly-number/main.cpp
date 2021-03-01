#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    int n = 12;
    std::vector<int> primes{2, 7, 13, 19};
    Solution sln = Solution();
    auto res = sln.nthSuperUglyNumber(n, primes);
    std::cout << res << std::endl;
    return 0;
}
