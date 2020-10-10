#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> res;
        letterCombinationsHelper(res, digits, "", 0);
        return res;
    }

private:
    vector<string> mapping{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void letterCombinationsHelper(vector<string> &res, string digits, string str, int n) {
        if (n == digits.size()) {
            res.push_back(str);
            return;
        }
        string letter = mapping[digits[n] - '0'];  // get corresponding letter e.g. 2->"abc"
        for (auto ch : letter) {
            str += ch;
            letterCombinationsHelper(res, digits, str, n + 1);
            str.pop_back();
        }
    }
};
