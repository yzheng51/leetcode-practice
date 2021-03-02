# Find Minimum in Rotated Sorted Array

## 描述

假设按照升序排序的数组在预先未知的某个点上进行了旋转。例如，数组 `[0,1,2,4,5,6,7]` 可能变为 `[4,5,6,7,0,1,2]` 。

请找出其中最小的元素。

```
输入：nums = [3,4,5,1,2]
输出：1
```
```
输入：nums = [4,5,6,7,0,1,2]
输出：0
```
```
输入：nums = [1]
输出：1
```

提示：

- `1 <= nums.length <= 5000`
- `-5000 <= nums[i] <= 5000`
- `nums` 中的所有整数都是 唯一 的
- `nums` 原来是一个升序排序的数组，但在预先未知的某个点上进行了旋转

## 解法

经典的二分法练习题，重点在于循环终止条件，`nums[left] == nums[mid]` 位置和 `left/right` 值变更的条件判断。比较好的方案是先按二分查找的模板写出代码后，

```cpp
// 二分查找模板
int binarySearch(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    return -1;
}
```

分别取一个二维数组和三维数组代入做测试。在本题中可以将`[1, 2]` 和 `[2, 1]` 依次带入代码中后可以将 `nums[left] == nums[mid]` 合并入 `nums[left] < nums[mid]` 的条件中。代入 `[3, 1, 2]` 可以将 `right = mid - 1` 调整为 `right = mid` 。

## 代码

```cpp
class Solution {
public:
    int findMin(std::vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int res = nums[left];

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[left] <= nums[mid]) {
                res = std::min(res, nums[left]);
                left = mid + 1;
            } else {
                res = std::min(res, nums[right]);
                right = mid;
            }
        }
        return res;
    }
};
```
