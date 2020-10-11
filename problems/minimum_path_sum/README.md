# Minimum Path Sum

## 描述

给定一个包含非负整数的 `m x n` 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

```
输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
```

## 解法

此题为动态规划的经典例子。假设 `dp[i][j]` 表示从网格左上角走到 `grid[i][j]` 路径总和最小，那么 `dp[m - 1][n - 1]` 就是题目要求的答案。首先填入第一行和第一列的值，由于第一行只能往右走，第一列只能往下走，所以只需累加之前的数字即可。然后按顺序遍历网格，判断上方和左方的最小路经总和哪个较小并加上网格当前位置的值作为当前的最小路经总和。最后加上边界条件的判断，代码如下

## 代码

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, grid[0][0]));

        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
```
