# Combinations

## 描述

给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

```
输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
```

## 解法

此题可以用深度优先搜索解决，主要的注意点是循环的起始值是 `1` 和递归的终止条件

## 代码

```cpp
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        dfs(res, n, k, {}, 1);
        return res;
    }

private:
    void dfs(vector<vector<int>> &res, int n, int k, vector<int> curr, int m) {
        if (curr.size() == k) {
            res.push_back(curr);
            return;
        }
        for (int i = m; i <= n; ++i) {
            curr.push_back(i);
            dfs(res, n, k, curr, i + 1);
            curr.pop_back();
        }
    }
};
```
