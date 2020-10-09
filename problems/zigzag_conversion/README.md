# Zigzag Conversion

## 描述

将一个给定字符串根据给定的行数，以从上往下、从左到右进行 `Z` 字形排列。

比如输入字符串为 `"LEETCODEISHIRING"` 行数为 `3` 时，排列如下：
```
L   C   I   R
E T O E S I I G
E   D   H   N
```
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如：`"LCIRETOESIIGEDHN"`。

请你实现这个将字符串进行指定行数变换的函数：

`string convert(string s, int numRows);`

```
输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
```
```
输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G
```

## 解法

建立一个以 `string` 为元素的 `vector` 容器来保存结果，其中每个 `string` 为最终结果的一行。那么可以从左到右遍历原字符串，从上至下再下至上添加到容器的每个元素中，最后按正常顺序输出容器中的所有元素。注意边界条件的判断。

## 代码

```cpp
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
```
