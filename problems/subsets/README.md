# Subsets

## 描述

给定一组不含重复元素的整数数组 `nums`，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

```
输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
```

## 解法

此题可以用深度优先搜索解决，由于最终结果要求是集合，这里循环的起始值设置为 `i = n` 以保证搜索完 `2` 之后不会往前搜索 `1`，同时也起到了递归终止条件的作用，即当 `n > size(nums)` 时不进行任何操作。这里需要注意，由于采用的是深度优先搜索，最终结果的顺序应该如下

```
[
    [],
    [1],
    [1,2],
    [1,2,3],
    [1,3],
    [2],
    [2,3],
    [3]
]
```

## 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res = {{}};
        dfs(res, nums, {}, 0);
        return res;
    }

private:
    void dfs(vector<vector<int>> &res, vector<int> nums, vector<int> curr, int n) {
        for (int i = n; i < nums.size(); ++i) {
            curr.push_back(nums[i]);
            res.push_back(curr);
            dfs(res, nums, curr, i + 1);
            curr.pop_back();
        }
    }
};
```
