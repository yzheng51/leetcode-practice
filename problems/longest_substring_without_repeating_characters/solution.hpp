#include <algorithm>
#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int res = 0;
        int start = 0;
        std::unordered_map<char, int> mp;

        for (int i = 0; i < s.size(); ++i) {
            if (mp.count(s[i])) {
                start = std::max(start, mp[s[i]] + 1);
            }
            mp[s[i]] = i;
            res = std::max(res, i - start + 1);
        }
        return res;
    }
};