#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.size() <= 1) {
            return s;
        }
        int start = 0;
        int maxLen = 1;
        int n = s.size() - 1;
        for (int curr = 0; curr < s.size();) {
            int left = curr;
            int right = curr;
            while (right < n && s[right + 1] == s[right])
                ++right;       // Skip duplicate characters in the middle
            curr = right + 1;  // for next iter
            while (right < n && left > 0 && s[left - 1] == s[right + 1]) {
                ++right;
                --left;
            }
            int new_len = right - left + 1;  // record best palindro
            if (new_len > maxLen) {
                start = left;
                maxLen = new_len;
            }
        }
        return s.substr(start, maxLen);
    }
};