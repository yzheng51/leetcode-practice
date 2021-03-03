# Rotate Image

## 描述

给定一个 `n × n` 的二维矩阵 `matrix` 表示一个图像。请你将图像顺时针旋转 `90` 度。

你必须在 **原地** 旋转图像，这意味着你需要直接修改输入的二维矩阵。**请不要** 使用另一个矩阵来旋转图像。

```
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[7,4,1],[8,5,2],[9,6,3]]
```
```
输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
```
```
输入：matrix = [[1]]
输出：[[1]]
```
```
输入：matrix = [[1,2],[3,4]]
输出：[[3,1],[4,2]]
```

提示：

- `matrix.length == n`
- `matrix[i].length == n`
- `1 <= n <= 20`
- `-1000 <= matrix[i][j] <= 1000`

## 解法

由于本题目的为将横向元素反转为纵向，若直接对应交换需要考虑临时变量存储被覆盖的元素，不容易想到解法，因而可使用矩阵转置来做辅助操作，先把列元素放到对应的行上，再每行做翻转。

## 代码

```cpp
class Solution {
public:
    void rotate(std::vector<std::vector<int>> &matrix) {
        int n = matrix.size();
        // transpose
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        // reflect
        for (int i = 0; i < n; ++i) {
            for (int j = 0, k = n - 1; j < k; ++j, --k) {
                std::swap(matrix[i][j], matrix[i][k]);
            }
        }
    }
};
```
