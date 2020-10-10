#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    std::string haystack = "abcdabcdabde";
    std::string needle = "abcdabd";
    Solution sln;
    auto res = sln.strStr(haystack, needle);
    std::cout << res << std::endl;
    return 0;
}
