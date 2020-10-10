# Search In Rotated Sorted Array

## 描述

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

例如，数组 `[0,1,2,4,5,6,7]` 可能变为 `[4,5,6,7,0,1,2]`

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 `-1` 。

你可以假设数组中不存在重复的元素。你的算法时间复杂度必须是 $O(log n)$ 级别。

```
输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
```
```
输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
```

## 解法

以二分法为基础，`arr[mid]` 两边必有一侧的部分是有序数列，则可以在该有序部分找 `target`。如果不存在，那就从无序部分入手。重复上述操作。

## 代码

```cpp
class Solution {
public:
    int search(std::vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] >= nums[left]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
```
