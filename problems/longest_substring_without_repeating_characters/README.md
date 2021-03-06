# Longest Substring Without Repeating Characters

## 描述

给定一个字符串，请你找出其中不含有重复字符的**最长子串**的长度。
```
输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
```
```
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
```
```
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
```

## 解法

由于此题中需要判断 "无重复" ，所以不难想到需要用集合或者哈希表来存储已遍历到的字符。本题重点在于当遍历到一个与维护的表中重复的字符的处理方法。考虑描述中的第一个例子，当维护的表中已经存在 `a, b, c` 了，循环遍历到第四个位置上的 `a` ，此时应该将最长字串的起始点从第一个字符 `a` 移动到第二个字符 `b` ，这样就用了最小的移动距离来保证不重复子串。那么很明显，我们需要知道重复的那个字符所在的位置，于是我们建立映射 $f$
$$
f(x_i)=i
$$
其中 $i$ 是元素 $x_i$ 的下标。同时，如果遍历到重复元素 $x_j=x_i$，元素 $x_i$ 对应的值 $i$ 需要被修改为当前元素的下标 $j$，即
$$
f(x_i)=j
$$
所以，该映射的值是该元素在已遍历过的字符中最后出现时对应的下标。程序中可以用哈希表来实现上述映射。因为题目只需要求出最长字串的长度，所以程序中我们用 `start` 来存储不重复子串的起始位置，用 `i - start + 1` 来计算当前子串的长度，维护 `res` 来保存最长子串，即
$$
res=\max\{res, i-start+1\}
$$
这里需要注意对子串起始位置的判断，比如对字符串 `abba` ，当遍历到第三个元素 `b` 时，起始位置应该移动到上一个出现 `b` 的下一个位置，即第二个位置的下一个位置，也就是当前位置。继续遍历第四个元素 `a` 会发现上一个 `a` 出现在第一个位置，这时候起始位置应该保持在第三个位置不动，而不是向左移动，这一操作可以表示为
$$
start=\max\{start, f(x_i)+1\}
$$
完整代码如下

## 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int res = 0;
        int start = 0;
        std::unordered_map<char, int> mp;

        for (int i = 0; i < s.size(); ++i) {
            if (mp.count(s[i])) {
                start = std::max(start, mp[s[i]] + 1);
            }
            mp[s[i]] = i;
            res = std::max(res, i - start + 1);
        }
        return res;
    }
};
```
