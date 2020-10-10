#include <string>
#include <vector>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.empty()) {
            return 0;
        }
        int n1 = haystack.size();
        int n2 = needle.size();
        int i = 0, j = 0;
        std::vector<int> next(n2);
        getNext(needle, next);
        while (i < n1 && j < n2) {
            if (j == -1 || haystack[i] == needle[j]) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
        }
        return (j == n2) ? i - j : -1;
    }

private:
    void getNext(std::string needle, std::vector<int> &next) {
        int n = needle.size();
        int j = 0;
        int k = -1;
        next[j] = k;
        while (j < n - 1) {
            if (k == -1 || needle[k] == needle[j]) {
                next[++j] = ++k;
            } else {
                k = next[k];
            }
        }
    }
};
