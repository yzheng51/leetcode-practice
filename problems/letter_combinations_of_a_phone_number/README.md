# Letter Combinations Of A Phone Number

## 描述

给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

![alt text](/images/phone-number.png)

```
输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
```

## 解法

由于每个数字都有对应的多个字母，首先需要建立一个数据结构来告诉程序这样的映射，可以选择哈希表或者数组，这里选择用数组的下标和其对应的值来表示这个映射。然后使用递归版本的回溯算法来解决，遍历每个数字对应的字符串，找出所有可能的组合。

## 代码

```cpp
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
```
