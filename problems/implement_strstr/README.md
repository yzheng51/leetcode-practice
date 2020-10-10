# Implement strStr()

## 描述

实现 strStr() 函数。

给定一个 `haystack` 字符串和一个 needle 字符串，在 `haystack` 字符串中找出 `needle` 字符串出现的第一个位置 (从0开始)。如果不存在，则返回 `-1`。

```
输入: haystack = "hello", needle = "ll"
输出: 2
```
```
输入: haystack = "aaaaa", needle = "bba"
输出: -1
```

说明:

当 `needle` 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 `needle` 是空字符串时我们应当返回 `0` 。这与C语言的 `strstr()` 以及 `Java` 的 `indexOf()` 定义相符。

## 解法 (暴力匹配)

此题比较容易想到的做法就是创建两个游标 `i` 和 `j` 分别遍历 `haystack` 和 `needle` ，如果当前字符串不相同则 `i` 向后移动一位，如果相同则比较两个字符串的下一个是否相同，直到不同或超出字符串边界为止。因此，匹配到最后情况分为三种

- `i` 超出边界

  说明遍历完 `haystack` 都没有找到 `needle` ，根据题意返回 `-1`
- `j` 超出边界

  说明 `j` 已经和 `needle` 的长度相等，只需通过 `i - j` 得到起始位置返回即可
- 两个游标均未超出边界但当前两游标对应的字符不同

  此时，`i` 应回到已匹配子串开头的下一个位置，同时将 `j` 归零。考虑以下例子

  ```
  haystack = "abcdabcdabde"
  needle = "abcdabd"
  ```

  当匹配到 `haystack[6] != needle[6]` 时， `i` 应从 `6` 移动到 `1`， 因为已匹配子串的开头位置是 `haystack[0]` 同时令 `j = 0`

根据题意，添加上边界条件的判断后，上述暴力解法的代码如下

## 代码 (暴力匹配)

```cpp
class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.empty()) {
            return 0;
        }
        int n1 = haystack.size();
        int n2 = needle.size();
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (haystack[i] == needle[j]) {
                ++i;
                ++j;
            } else {
                i = i - j + 1;
                j = 0;
            }
        }
        return (j == n2) ? i - j : -1;
    }
};
```

## 解法 (KMP算法)

上述暴力解法虽然解决了问题，但做了许多多余的计算，依旧考虑下面的例子

```
haystack = "abcdabcdabde"
needle = "abcdabd"
```

当匹配到 `haystack[6] != needle[6]` 时，上述解法将目标字符串的游标从 `6` 移动到 `1` ，但是由于这部分已经被遍历过，计算机理论上是可以知道这一段是不可能匹配成功的。事实上，的确存在一个更加高效的算法能解决此类问题

1977年，`James H. Morris` ，`Donald Knuth` 和 `Vaughan Pratt` 三人联合发表了一种字符串匹配算法用来解决此类问题，该算法也用他们三人的名字被命名为 `Knuth–Morris–Pratt (KMP)` 算法。该方法以匹配串为基础通过建立一个**部分匹配表**来保存其游标的下一个潜在位置。考虑上面的例子，其部分匹配表可以建立如下

| 匹配串     | a   | b   | c   | d   | a   | b   | d   |
| ---------- | --- | --- | --- | --- | --- | --- | --- |
| 部分匹配表 | -1  | 0   | 0   | 0   | 0   | 1   | 2   |

部分匹配表 `next[i]` 中的每个值表示的是当前位置之前有多少个连续字符和整个匹配串有公共的前缀。考虑表中的最后一个数 `next[6] = 2` ，其含义为在 `needle[6] = d` 之前有 `2` 个连续字符 `ab` 和整个匹配串的开头 `2` 个字符是相同的。

再次考虑上面的例子，当匹配到 `haystack[6] != needle[6]` 时，我们不改变目标串的游标 `i` ，而只改变匹配串的游标为 `next[6]` ，那么下一个循环中比较的两个字符就为 `haystack[6]` 和 `needle[2]` 。有趣的是，目标串该位置之前的两个字符 `"ab"` 满足匹配串的要求，而且在 `KMP` 算法下我们完全不需要回溯 `i` 的位置。

相对于暴力匹配，我们只需事先算好部分匹配表，然后将回溯部分改为 `j = next[j]` 即可，代码如下

## 代码 (KMP算法)

```cpp
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
        int i = 0;
        int k = -1;
        next[i] = k;
        while (i < n - 1) {
            if (k == -1 || needle[k] == needle[i]) {
                next[++i] = ++k;
            } else {
                k = next[k];
            }
        }
    }
};
```
