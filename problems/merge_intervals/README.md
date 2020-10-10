# Merge Intervals

## 描述

给出一个区间的集合，请合并所有重叠的区间。

```
输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
```
```
输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
```

## 解法

此题明显需要比较区间的右边界和下一个区间的左边界来判断是否需要合并，由此我们需要从小大大排序区间，大小条件为各个区间的左边界，排序后可以得到一系列左边界从小到大的区间。然后我们依次遍历区间，如果可以合并则持续合并，直到不能合并为止。一旦遇到不能合并的区间，先将原来的区间放入结果集，然后将当前区间设为此无法被合并的区间。代码如下

>这里为了节省空间使用，直接用 `res` 的最后一个元素 `res.back()` 来表示当前元素

## 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.empty()) {
            return {};
        }
        int n = intervals.size();
        vector<vector<int>> res;
        std::sort(intervals.begin(), intervals.end(), [](vector<int> x, vector<int> y) { return x[0] < y[0]; });
        res.push_back(intervals[0]);
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] <= res.back()[1]) {
                res.back()[1] = std::max(intervals[i][1], res.back()[1]);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
```
