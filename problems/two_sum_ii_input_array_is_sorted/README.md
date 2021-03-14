# Two Sum II - Input array is sorted

## 描述

给定一个已按照 **升序排列**  的整数数组 `numbers` ，请你从数组中找出两个数满足相加之和等于目标数 `target` 。

函数应该以长度为 `2` 的整数数组的形式返回这两个数的下标值。`numbers` 的下标 从 `1` 开始计数 ，所以答案数组应当满足 `1 <= answer[0] < answer[1] <= numbers.length` 。

你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
```
输入：numbers = [2,7,11,15], target = 9
输出：[1,2]
解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
```
```
输入：numbers = [2,3,4], target = 6
输出：[1,3]
```
```
输入：numbers = [-1,0], target = -1
输出：[1,2]
```

提示：

- `2 <= numbers.length <= 3 * 104`
- `-1000 <= numbers[i] <= 1000`
- `numbers` 按 递增顺序 排列
- `-1000 <= target <= 1000`
- 仅存在一个有效答案

## 解法

由于数组已排好序，不需要像 [Two Sum](../two_sum/) 一样额外建立空间，只需双指针分别从数组前后往中间遍历即可。

- 等于指定值即刻返回
- 小于指定值，说明左端应该增大
- 大于指定值，说明右端应该减小

## 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1};
            } else if (sum > target) {
                --right;
            } else if (sum < target) {
                ++left;
            }
        }
        return {};
    }
};
```
