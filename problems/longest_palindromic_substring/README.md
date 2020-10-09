# Longest Palindromic Substring

## 描述

给定一个字符串 `s`，找到 `s` 中最长的回文子串。你可以假设 `s` 的最大长度为 `1000`。
```
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
```
```
输入: "cbbd"
输出: "bb"
```

## 解法

从头开始遍历字符串，以当前字符为起点分别向左右展开，判断是否为回文字符串。如果是，则记录当前长度与最大长度作比较。反之，则将游标移动到下一个位置。考虑例子中的 `"babad"` ，初始化三个游标 `left, curr, right` ，其中 `curr` 是当前字符的下标，`left` 和 `right` 以 `curr` 为初始值，当游标遍历到字符串的第二个元素 `a` 时，判断当前 `a` 左右两边的元素是否相等，即 `s[right + 1] = s[left - 1]` 是否成立。如果下一次展开不成立，则记录当前字符串长度 `right - left + 1` 并将其与一个在循环中维护的最大回文字符串作比较。为了方便，这里将最大回文字符串表示为其起点和其长度组成的元组，在程序最后用切片的方式返回。

此题还有一个要点，如果当前字符串与后一个重复，即题目描述中的第二个例子 `"cbbd"`，需要将右游标往后移动到不重复为止。同时，下一次循环中 `curr` 的初始值的位置变为重复字符最后一次出现的下一个位置。最后，每次增加 `right` 或减小 `left` 时记得判断是否超出字符串本身的边界。完整代码如下

## 代码

```cpp
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.size() < 2) {
            return s;
        }
        int n = s.size();
        int start = 0;
        int maxLen = 1;
        for (int curr = 0; curr < n;) {
            int left = curr;
            int right = curr;
            while (right < n - 1 && s[right + 1] == s[right])
                ++right;       // Skip duplicate characters in the middle
            curr = right + 1;  // for next iter
            while (right < n - 1 && left > 0 && s[left - 1] == s[right + 1]) {
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
```
