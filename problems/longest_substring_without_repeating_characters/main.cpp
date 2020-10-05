#include <iostream>
#include "solution.hpp"

int main(int argc, char const *argv[]) {
    std::string s = "abba";
    Solution sln;
    int res = sln.lengthOfLongestSubstring(s);
    std::cout << res << std::endl;
    return 0;
}
