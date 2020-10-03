# Two Sum

## 描述

给定一个整数数组 `nums` 和一个目标值 `target`，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
```
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
```

## 解法

将数组中的某元素 `x` 与其对应的数 `target - x` 作为键，此时 `x` 的下标作为值，即建立映射 $f$
$$
f(target-x_i)=i
$$
并记录已经计算过的 `target - x` 。在程序中可以用哈希表来实现上述数据结构。考虑描述中的示例，当遍历数组中第一个数 `2` 时，在哈希表 `mp` 中建立映射 `9 - 2 -> 0`。因此当遍历第二个元素 `7` 时，会发现当前值已经存在于哈希表中，由于表中的下标一定比当前下标小而且题中说明答案只有一个，所以按从小到大的顺序返回 $(mp[x_i], i)$。最后，当哈希表中没有找到相应元素的时候返回空数组。

## 代码

```cpp
class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        int n = nums.size();
        std::unordered_map<int, int> mp;
        for (int i = 0; i != n; ++i) {
            int curr = nums[i];
            if (mp.count(curr)) {
                 return {mp[curr], i};
            }
            else {
               mp[target - curr] = i;
            }
        }
        return {};
    }
};
```
