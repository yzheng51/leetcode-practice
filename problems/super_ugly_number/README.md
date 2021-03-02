# Super Ugly Number

## 描述

编写一段程序来查找第 `n` 个超级丑数。

超级丑数是指其所有质因数都是长度为 `k` 的质数列表 `primes` 中的正整数。

```
输入: n = 12, primes = [2,7,13,19]
输出: 32
解释: 给定长度为 4 的质数列表 primes = [2,7,13,19]，前 12 个超级丑数序列为：[1,2,4,7,8,13,14,16,19,26,28,32] 。
```

说明:

- `1` 是任何给定 `primes` 的超级丑数。
- 给定 `primes` 中的数字以升序排列。
- 0 < `k` ≤ 100, 0 < `n` ≤ 106, 0 < `primes[i]` < 1000 。
- 第 `n` 个超级丑数确保在 `32` 位有符整数范围内。

## 解法

参考 [ugly number ii](../ugly_number_ii/), 将原题中的 `[2, 3, 5]` 当作数组变量输入

## 代码

```cpp
class Solution {
public:
    int nthSuperUglyNumber(int n, std::vector<int> &primes) {
        int n_primes = primes.size();
        std::vector<int> counter(n_primes, 0);
        std::vector<int> dp(n);

        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            int temp = INT_MAX;
            for (int j = 0; j < n_primes; ++j) {
                temp = std::min(temp, primes[j] * dp[counter[j]]);
            }
            dp[i] = temp;
            for (int j = 0; j < n_primes; ++j) {
                if (dp[i] == primes[j] * dp[counter[j]]) {
                    ++counter[j];
                }
            }
        }
        return dp[n - 1];
    }
};
```
