# Median Of Two Sorted Arrays

## 描述

给定两个大小为 `m` 和 `n` 的有序数组 `nums1` 和 `nums2`。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 $O(\log({m + n}))$。

你可以假设 `nums1` 和 `nums2` 不会同时为空。
```
nums1 = [1, 3]
nums2 = [2]
则中位数是 2.0
```
```
nums1 = [1, 2]
nums2 = [3, 4]
则中位数是 (2 + 3)/2 = 2.5
```

## 解法 (归并排序)

对两有序数组进行操作很容易联想到归并排序算法，将两数组合并后直接找出待求的元素。不过由于只需要找出中位数，所以当新数组增加到 `median + 1` 的时候就可以返回中位数。该算法时间复杂度为 $O(m+n)$

## 代码 (归并排序)

```cpp
class Solution {
public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int size = n1 + n2;
        int median = size / 2;
        int i = 0, j = 0, k = 0;
        std::vector<int> arr(median + 1);
        while (i != n1 && j != n2 && i + j <= median) {
            if (nums1[i] < nums2[j])
                arr[k++] = nums1[i++];
            else
                arr[k++] = nums2[j++];
        }
        while (i != n1 && i + j <= median) {
            arr[k++] = nums1[i++];
        }
        while (j != n2 && i + j <= median) {
            arr[k++] = nums2[j++];
        }
        return (size % 2 != 0) ? arr[median] : (arr[median - 1] + arr[median]) / 2.0;
    }
};
```

## 解法 (二分查找)

由于题目要求是 $O(\log({m + n}))$ ，要达到这个性能需要使用分治法。结合数组中求第 `k` 小元素的思想，我们可以分别求出两个有序数组中第 `k / 2` 个元素，然后将较小的一组去掉，这样一次操作规模就变成了 `k / 2` ，之后再求去掉后的数组中的第 `k / 2` 个元素，不停递归直到 `k=1` 或者长度较小的数组中所有元素被取完。

由于题目中要求的是中位数，数组长度的奇偶性会影响操作。这里将两种情况合并，当最终数组长度为奇数时，即 $m = n$ 时, `findMedianSortedArrays()` 中最后一行的两个 `getKth()` 会计算两个相同的值。
除此之外，取第 `k / 2` 元素时候还需判断该值是否已经大于数组的大小，如果是，直接去掉该数组。该算法时间复杂度为 $O(\log({m + n}))$。

## 代码 (二分查找)

```cpp
class Solution {
public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int m = (n1 + n2 + 1) / 2;
        int n = (n1 + n2 + 2) / 2; // median position =  (m + n) / 2
        return (getKth(nums1, 0, n1 - 1, nums2, 0, n2 - 1, m) + getKth(nums1, 0, n1 - 1, nums2, 0, n2 - 1, n)) / 2.0;
    }

private:
    int getKth(std::vector<int> &nums1, int l1, int r1, std::vector<int> &nums2, int l2, int r2, int k) {
        int n1 = r1 - l1 + 1;
        int n2 = r2 - l2 + 1;

        // assume size(nums1) > size(nums2)
        // otherwise, swap two array
        if (n1 > n2) {
            return getKth(nums2, l2, r2, nums1, l1, r1, k);
        }
        // stop condition: size(nums1) = 0 or k = 1
        if (n1 == 0) {
            return nums2[l2 + k - 1];
        }
        if (k == 1) {
            return std::min(nums1[l1], nums2[l2]);
        }
        // avoid array size is smaller than k / 2
        int i = l1 + std::min(n1, k / 2);
        int j = l2 + std::min(n2, k / 2);
        if (nums1[i - 1] > nums2[j - 1]) {
            return getKth(nums1, l1, r1, nums2, j, r2, k - (j - l2));
        } else {
            return getKth(nums1, i, r1, nums2, l2, r2, k - (i - l1));
        }
    }
};
```
