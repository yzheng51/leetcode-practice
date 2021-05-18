# Search a 2D Matrix

## 描述

编写一个高效的算法来判断 `m x n` 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

- 每行中的整数从左到右按升序排列。
- 每行的第一个整数大于前一行的最后一个整数。

```
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true
```
```
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false
```

提示：

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 100`
- `-104 <= matrix[i][j], target <= 104`

## 解法 (搜索)

从右上角开始遍历，由于右上角必定是改行最大，因此若 `target` 比当前元素大，可直接跳到下一行。若 `target` 比当前元素小，则数存在的话必定在该行。此解法没有充分利用有序的条件，时间复杂度为 $O(m + n)$

## 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int i = 0;
        int j = matrix[0].size() - 1;
        int rows = matrix.size();

        while (i < rows && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                ++i;
            } else if (matrix[i][j] > target) {
                --j;
            }
        }
        return false;
    }
};
```

## 解法 (二分)

有序数组中查找显然能想到二分搜索，根据题意可以先用二分法判断数在哪一行。这一步需要注意条件，若小于 `target` 需要对该行所有数恒成立，即用改行最后一个数去比较。同理若大于 `target` 要用该行第一个数去比较。找到所在行后就是一维数组的二分查找了。总时间复杂度为 $O(\log m + \log n)$

## 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int left = 0;
        int right = matrix.size() - 1;
        int mid;

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (matrix[mid][0] == target) {
                return true;
            }
            if (matrix[mid].back() < target) {
                left = mid + 1;
            } else if (matrix[mid][0] > target) {
                right = mid - 1;
            } else {
                break;
            }
        }

        left = 0;
        right = matrix[mid].size() - 1;
        int curr = mid;

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (matrix[curr][mid] == target) {
                return true;
            } else if (matrix[curr][mid] < target) {
                left = mid + 1;
            } else if (matrix[curr][mid] > target) {
                right = mid - 1;
            }
        }

        return false;
    }
};
```
