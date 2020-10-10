# Regular Expression Matching

## 描述

给你一个字符串 `s` 和一个字符规律 `p`，请你来实现一个支持 `'.'` 和 `'*'` 的正则表达式匹配。

`'.'` 匹配任意单个字符
`'*'` 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 `s` 的，而不是部分字符串。

说明:

`s` 可能为空，且只包含从 `a-z` 的小写字母。
`p` 可能为空，且只包含从 `a-z` 的小写字母，以及字符 `.` 和 `*`。

```
输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
```
```
输入:
s = "aa"
p = "a*"
输出: true
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。
因此，字符串 "aa" 可被视为 'a' 重复了一次。
```
```
输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
```
```
输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
```
```
输入:
s = "mississippi"
p = "mis*is*p*."
输出: false
```

## 解法

两个字符串的匹配问题，很容易联想到经典的最短编辑距离问题。从分析 `p` 的最后一个字符 `p[i]` 开始，其只有三种可能

1. `p[i] = '.'`

   此时 `s[i]` 是什么字符无关最终的判断，因为 `'.'` 可以匹配任意单个字符。那么只要字符串 `p[0,...,i-1]` 和 `s[0,...,i-1]` 匹配，最终结果就是匹配的

2. `p[i] = '*'`
   - 匹配 `0` 个字符

      那么这时两字符串匹配需要满足 `p[0,...,i-2]` 和 `s[0,...,i]`

   - 匹配一个及以上的字符

      此处需要对 `s[i]` 开始的字符一个个往前判断。如果 `s[i] = p[i-1]` 或者 `p[i-1] = '.'` ，那么去掉 `s` 的最后一个字符，继续判断 `s[0,...,i-1]` 是否和 `p[0,...,i-1]` 匹配，直到不匹配为止。假设上一步迭代到最后的字符串为 `s[0,...,i-t]` 此时只需判断 `s[0,...,i-t]` 是否和 `p[0,...,i-2]` 匹配即可。

3. `p[i]` 是除了上述两字符以外的其他字符
    - `p[i] = s[i]`

       在这种情形下，和 `p[i] = '.'` 的情况一样，只需要判断 `p[0,...,i-1]` 和 `s[0,...,i-1]` 是否匹配

    - `p[i] != s[i]`

       那么显然这种情况下 `p` 不可能匹配 `s`

如果使用递归解决该问题，加上边界条件的判断，如 `p` 和 `s` 是否为空， `p` 数组大小的判断，初始代码如下

```cpp
class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        return isMatchHelper(s, s.size(), p, p.size());
    }

private:
    bool isMatchHelper(std::string s, int n1, std::string p, int n2) {
        int i = n1 - 1;  // n1 is size(s) and s[i] is the last element of s
        int j = n2 - 1;  // n2 is size(p) and p[j] is the last element of p
        // size(p) = 0
        if (n2 == 0) {
            return n1 == 0;
        }
        // size(p) = 1
        if (n2 == 1) {
            if (n1 != 1) {
                return false;
            }
            return p[0] == s[0] || p[0] == '.';
        }
        // size(p) > 1
        if (p[j] == '.') {
            if (n1 == 0) {
                return false;
            }
            return isMatchHelper(s, n1 - 1, p, n2 - 1);
        } else if (p[j] == '*') {
            if (n1 == 0) {
                return isMatchHelper(s, n1, p, n2 - 2);
            }
            if (p[j - 1] == s[i] || p[j - 1] == '.') {
                return isMatchHelper(s, n1, p, n2 - 2) || isMatchHelper(s, n1 - 1, p, n2);
            } else {
                return isMatchHelper(s, n1, p, n2 - 2);
            }
        } else {
            if (n1 == 0) {
                return false;
            }
            if (p[j] == s[i]) {
                return isMatchHelper(s, n1 - 1, p, n2 - 1);
            } else {
                return false;
            }
        }
    }
};
```

上述代码有许多部分可以合并，比如 `p[i] = '.'` 和 `p[i]` 是其他字符这两种情况条件差不多，可以写到一起，然后把 `s` 是否为空的条件也放进判断，虽然代码整体可读性降低，但是性能相对与初始版本有所提升。

## 代码 (递归)

```cpp
class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        return isMatchHelper(s, s.size(), p, p.size());
    }

private:
    bool isMatchHelper(std::string s, int n1, std::string p, int n2) {
        int i = n1 - 1;  // n1 is size(s) and s[i] is the last element of s
        int j = n2 - 1;  // n2 is size(p) and p[j] is the last element of p
        // size(p) = 0
        if (n2 == 0) {
            return n1 == 0;
        }
        // size(p) = 1
        if (n2 == 1) {
            return n1 == 1 && (p[0] == s[0] || p[0] == '.');
        }
        // size(p) > 1
        if (p[j] == '*') {
            return isMatchHelper(s, n1, p, n2 - 2) || n1 != 0 && (p[j - 1] == s[i] || p[j - 1] == '.') && isMatchHelper(s, n1 - 1, p, n2);
        } else {
            return n1 != 0 && (p[j] == s[i] || p[j] == '.') && isMatchHelper(s, n1 - 1, p, n2 - 1);
        }
    }
};
```

递归版本的解法中，明显有一些子问题的结果可以被复用，然而递归解法的假设是子问题之间独立，所以这些问题又被重复解决。为更好的利用这些已经被解决的子问题，我们可以用动态规划自下而上重写上述解法。假设 `dp[i][j]` 表示字符串 `s[0,...,i-1]` 是否能被 `p[0,...,j-1]` 匹配，其中 `i` 表示 `s` 的长度，`j` 表示 `p` 的长度。

由于动态规化是自下而上的解法，比起递归版本，该解法因为用到了 `dp[i-1][]` ，那么在进行主循环之前，必须先求出 `dp[0][]` 的值，这样就能保证 $i - 1 \ge 0$

## 代码 (动态规划)

```cpp
class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int n1 = s.size();
        int n2 = p.size();
        std::vector<std::vector<bool>> dp(n1 + 1, std::vector<bool>(n2 + 1));

        // i represent size(s) and j represent size(p)
        // size(p) = 0
        for (int i = 0; i <= n1; ++i) {
            dp[i][0] = (i == 0);
        }
        // size(p) = 1
        for (int i = 0; i <= n1; ++i) {
            dp[i][1] = (i == 1) && (p[0] == s[0] || p[0] == '.');
        }
        // Because main loop includes dp[i-1][]
        // so dp[0][] has to be computed first
        for (int j = 2; j <= n2; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            } else {
                dp[0][j] = false;
            }
        }
        // size(p) > 1
        for (int i = 1; i <= n1; ++i) {
            for (int j = 2; j <= n2; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[i - 1][j];
                } else {
                    dp[i][j] = (p[j - 1] == s[i - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
                }
            }
        }
        return dp[n1][n2];
    }
};
```
