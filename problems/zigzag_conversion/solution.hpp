#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        int n = s.size();
        std::string res;
        std::vector<std::string> vec(numRows);

        for (int i = 0; i < n;) {
            for (int j = 0; j < numRows && i < n; ++j) {
                vec[j].push_back(s[i++]);
            }
            for (int j = numRows - 2; j >= 1 && i < n; --j) {
                vec[j].push_back(s[i++]);
            }
        }
        for (auto str : vec) {
            res += str;
        }
        return res;
    }
};
