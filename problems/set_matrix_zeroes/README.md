# Set Matrix Zeroes

## 描述

给定一个 `m x n` 的矩阵，如果一个元素为 `0`，则将其所在行和列的所有元素都设为 `0`。请使用原地算法。

```
输入:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
```
```
输入:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
```

进阶:

- 一个直接的解决方案是使用 $O(mn)$ 的额外空间，但这并不是一个好的解决方案。
- 一个简单的改进方案是使用 $O(m+n)$ 的额外空间，但这仍然不是最好的解决方案。
- 你能想出一个常数空间的解决方案吗？

## 解法

一个简单的想法是由于只需判断某行和某列是否需要置零，可以建立两个长度分别为 `m` 和 `n` 的数组在遍历矩阵的过程中判定该行或该列是否需要被置零。然后再遍历一遍矩阵，用存储的两个数列来确定矩阵最终的输出值，该算法的空间复杂度为 $O(m+n)$ ，代码如下

## 代码

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.empty()) {
            return;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> rows(m, false);
        vector<bool> cols(n, false);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rows[i] = (matrix[i][j] == 0) || rows[i];
                cols[j] = (matrix[i][j] == 0) || cols[j];
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = (rows[i] || cols[j]) ? 0 : matrix[i][j];
            }
        }
    }
};
```

## 解法 (常数空间)

由于题目需要常数空间复杂度的解决方案，我们考虑一个改进的方案。虽然上一个算法新建了两个以布尔值为元素的数组来存储某行或者某列是否需要被置零，事实上我们可以直接将这个判断存储在输入矩阵某行与某列中，但是相应的行列的信息就会丢失，因此我们需要优先判断被选中的行列是否需要被置零，然后将判断结果存储在该行列中，那么最简单的方案就是选择首行和首列。虽然空间复杂度被优化到 $O(1)$ ，但是时间复杂度还是和上一个算法一样为 $O(mn)$ ，代码如下

## 代码 (常数空间)

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.empty()) {
            return;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowZero = false;
        bool firstColZero = false;
        // check first row and first col
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }
        // traverse other elements and store 0 or not
        // in the first row and first col
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // check and change the values in the first row and col
        if (firstColZero) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
        if (firstRowZero) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }
    }
};
```
