# Palindrome Number

## 描述

判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
```
输入: 121
输出: true
示例 2:
```
```
输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
```
```
输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
```

## 解法

首先排除负数。目标是两个指针分别从前、后两个位置向中间取数然后比较，如果不符合条件直接返回 `false`，反之则继续遍历，其终止条件为遍历完整个数。为此我们需要提前知道该数组有多少个位数。

## 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int res = 0, cnt = 1;
        for (int y = x / 10; y != 0; y /= 10) {
            cnt *= 10;
        }

        for (int y = x; y != 0; y /= 10, cnt /= 10) {
            res = 10 * res + y % 10;
            if (res != x / cnt) {
                return false;
            }
        }
        return res == x;
    }
};
```
