# Best Time to Buy and Sell Stock

## 描述

给定两个字符串形式的非负整数 `num1` 和 `num2` ，计算它们的和。

提示：

- `num1` 和 `num2` 的长度都小于 `5100`
- `num1` 和 `num2` 都只包含数字 `0-9`
- `num1` 和 `num2` 都不包含任何前导零
- 你不能使用任何內建 `BigInteger` 库， 也不能直接将输入的字符串转换为整数形式

## 解法

本题关键点在于进位部分的处理，这里使用一个变量 `c` 来保存是否进位。代码中为了简单起见使用到了 `reverse()` 函数来反转字符串，可以通过提前判断字符串应有长度后，一个个往里面填数来改进。

## 代码

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size() - 1;
        int n2 = num2.size() - 1;
        int c = 0;

        string res;

        while (n1 >= 0 || n2 >= 0 || c) {
            int s = 0;
            if (n1 >= 0) {
                s += num1[n1--] - '0';
            }
            if (n2 >= 0) {
                s += num2[n2--] - '0';
            }
            s += c;
            c = s / 10;
            s = s % 10;

            res.push_back(s + '0');
        }
        reverse(res.begin(), res.end());

        return res;
    }
};
```
