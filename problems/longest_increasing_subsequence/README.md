# Longest Increasing Subsequence

## 描述

给定一个无序的整数数组，找到其中最长上升子序列的长度。

```
输入: [10,9,2,5,3,7,101,18]
输出: 4
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
```

说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 $O(n^2)$ 。

进阶: 你能将算法的时间复杂度降低到 $O(n\log{n})$ 吗?

## 解法 (动态规划)

非常经典的动态规划题，假设输入数组为 `nums` ，`dp[i]` 表示数组 `nums[0,...i-1]` 中以 `nums[i-1]` 为最后一个元素的最长上升子序列长度，其中初始值为 `1` ，即 `dp[0] = 1`。固定当前值 `nums[i]` 遍历之前的所有值，即 `nums[j]` ，其中 $j < i$ 。如果当前值比较大，即 `nums[i] > nums[j]`，那么 `dp[i] = dp[j] + 1` 。所有不难可知，如果有 `nums[i] > nums[j]`，那么下式成立
$$
dp[i]=\max\limits_{0 \le j < i}\{dp[j]+1\}
$$
同时，整个数组的最长上升子序列长度 `dp[n]` 为
$$
dp[n]=\max\limits_{0 \le i < n}\{dp[i]\}
$$
上述解法时间复杂度为 $O(n^2)$ ，代码如下

## 代码 (动态规划)

```cpp
class Solution {
public:
    int lengthOfLIS(std::vector<int> &nums) {
        int n = nums.size();
        int res = 0;
        std::vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            res = std::max(res, dp[i]);
        }
        return res;
    }
};
```

## 解法 (二分法)

进阶的时间复杂度要求为 $O(n\log{n})$ ，很容易想到要用二分法。由于本题只需要求出最长上升子序列的长度，而不是最长子序列本身，我们可以维护一个数组 `res` ，其每个元素 `res[i]` 表示原数组中长度为 `i + 1` 的所有上升子序列中的最小末元素。那么显然 `res` 的数组大小就是最长上升子序列的长度

考虑题目中的数组 `[10,9,2,5,3,7,101,18]`，

- 长度为 `1` 的上升子序列是数组中的每个元素，其最小末元素是 `2`
- 长度为 `2` 的上升子序列有
  ```
  [10, 101], [10, 18]
  [9, 101], [9, 18]
  [2, 5], [2, 3], [2, 7], [2, 101], [2, 18]
  [5, 7], [5, 101], [5, 18]
  [3, 7], [3, 101], [3, 18]
  [7, 101], [7, 18]
  ```
  其最小末元素是 `3` 。直觉上看，末元素越小的上升子序列，越可能成为被扩展为最长上升子序列，继续增加长度
- 长度为 `3` 的上升子序列有
  ```
  [2, 5, 7], [2, 5, 101], [2, 5, 18]
  [2, 3, 7], [2, 3, 101], [2, 3, 18]
  [2, 7, 101], [2, 7, 18]
  [5, 7, 101], [5, 7, 18]
  [3, 7, 101], [3, 7, 18]
  ```
  其最小末元素是 `7` 。可以看到，长度为 `2` 的上升子序列中只有末元素是 `3, 5, 7` 的最后被扩展为长度为 `3`，继续扩展
- 长度为 `4` 的上升子序列有
  ```
  [2, 5, 7, 101], [2, 5, 7, 18]
  [2, 3, 7, 101], [2, 3, 7, 18]
  ```
  其最小末元素是 `18` 。长度为 `3` 的上升子序列中只有末元素是 `7` 的长度被扩展为 `4`。由于不存在长度为 `5` 的上升子序列，此时 `res` 的元素为 `[2, 3, 7, 18]` ，其正好为最长上升子序列中的一个

一般的，我们可以证明 `res[i] < res[i + 1]` 即描述中的最小末元素是严格递增的 (这里假设最长上升子序列是严格递增的)，不过 `res` 的结果不一定是最长上升子序列中的一个。比如 `[2, 4, 5, 3, 7]` 的最长上升子序列为 `[2, 4, 5, 7]` ，但是最终得到的 `res` 为 `[2, 3, 5, 7]`，不过其长度和最长上升子序列是相同的。那么问题就变成了如何不通过枚举的方法来得到 `res` 。

事实上，我们可以在遍历原数组的过程中维护 `res` ，其逻辑为

- 当前元素 `nums[i]` 等于 `res` 的最后一个元素时

  不做任何操作或者理解为将 `res` 的最后一个元素修改为 `nums[i]`
- 当前元素 `nums[i]` 大于 `res` 的最后一个元素时

  直接在 `res` 的最后加上这个元素，显然保证了 `res` 依旧是递增的
- 当前元素 `nums[i]` 小于 `res` 的最后一个元素时

  找到 `res` 中第一个不小于 `nums[i]` 的元素，将其修改为 `nums[i]` ，由于 `res` 中的元素是严格单调递增的，我们可以用二分查找来完成上述操作

加上边界条件判断后，将上述思路转化为代码如下

```cpp
class Solution {
public:
    int lengthOfLIS(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> res;
        for (auto num : nums) {
            if (res.empty()) {
                res.push_back(num);
            }
            int left = 0;
            int right = res.size() - 1;
            if (res[right] < num) {
                res.push_back(num);
            } else {
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (res[mid] < num) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                res[left] = num;
            }
        }
        return res.size();
    }
};
```

上述代码中的边界条件可以和修改 `res` 中的元素合并。`res` 为空就表示 `left > right` ，并没有执行二分法部分的代码。如果程序执行了二分法，对二分法理解比较透彻的话可以知道跳出循环时，`left` 和 `right` 的值必然相等，此时若当前元素比 `res` 中所有元素都大，那么 `res[left] = res[right]` 是 `res` 的最后一个元素。由于这两种情况下都是向 `res` 的最后添加当前元素，我们可以将两个操作写进一个判断中，代码如下

## 代码 (二分法)

```cpp
class Solution {
public:
    int lengthOfLIS(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> res;
        for (auto num : nums) {
            int left = 0;
            int right = res.size() - 1;

            while (left < right) {
                int mid = (left + right) / 2;
                if (res[mid] < num) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            if (left > right || res[right] < num) {
                res.push_back(num);
            } else {
                res[left] = num;
            }
        }
        return res.size();
    }
};
```

由于用到 **第一个不小于** 这样的描述，我们也可以直接调用 `STL` 中的 `lower_bound()` 函数来简化代码的逻辑。不过上面二分法的操作还是需要掌握

## 代码 (STL)

```cpp
class Solution {
public:
    int lengthOfLIS(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> res;
        for (auto num : nums) {
            auto it = lower_bound(res.begin(), res.end(), num);
            if (it == res.end()) {
                res.push_back(num);
            } else {
                *it = num;
            }
        }
        return res.size();
    }
};
```
