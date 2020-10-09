#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    std::string s = "PAYPALISHIRING";
    int numRows = 4;
    Solution sln;
    auto res = sln.convert(s, numRows);
    std::cout << res << std::endl;
    return 0;
}
