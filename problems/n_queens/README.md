# N Queens

## 描述

`n` 皇后问题研究的是如何将 `n` 个皇后放置在 `n×n` 的棋盘上，并且使皇后彼此之间不能相互攻击。

![alt text](/images/8-queens.png)

上图为 `8` 皇后问题的一种解法。

给定一个整数 `n`，返回所有不同的 `n` 皇后问题的解决方案。

每一种解法包含一个明确的 `n` 皇后问题的棋子放置方案，该方案中 `'Q'` 和 `'.'` 分别代表了皇后和空位。

```
输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。
```

## 解法

由题可知，每行必定只有一个 `Q` 。因此我们可以将每种情况都列举出来最后一一判断是否符合条件，可能的情况有 $n^n$ ，显然这样的算法是很低效的。这里不难发现，有些情况不需要摆好全部的皇后就可以排除，这就是回溯算法。

此题为回溯算法的经典例题。我们首先按给定的 `n` 构造一个 `nxn` 的二维数组，其中每个元素都是 `.` ，在程序执行过程中，其每个元素会不停的被改为 `Q` 然后做判定。每当找到一个满足条件的二维数组，就将其加入最终结果集。整个算法基于递归，按上面说的，根据每一行只有一个 `Q` 这个条件，我们将递归终止条件设为遍历到第 `n` 行返回结果。然后每行中，对每一列的元素进行判断，是否能将当前元素更改为 `Q` 。如果能，改完之后把函数改为下一行递归调用，如果不能，则判断下一列元素。其中 `isValid()` 函数的三个循环分别是判定同一列和斜率互为相反数的两根对角线上是否已经存在 `Q` 。

显然大部分情况在没有走到第 `n` 行已经被排除了，大大的减少了计算量

## 代码

```cpp
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> nQueens(n, string(n, '.'));
        solveNQueens(res, nQueens, 0, n);
        return res;
    }

private:
    void solveNQueens(vector<vector<string>> &res, vector<string> nQueens, int row, int n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col) {
            if (isValid(nQueens, row, col, n)) {
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
        }
    }

    bool isValid(vector<string> nQueens, int row, int col, int n) {
        for (int i = 0; i != row; ++i) {
            if (nQueens[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (nQueens[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (nQueens[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};
```
