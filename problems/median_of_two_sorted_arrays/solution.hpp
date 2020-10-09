#include <algorithm>
#include <vector>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int m = (n1 + n2 + 1) / 2;
        int n = (n1 + n2 + 2) / 2;  // median position =  (m + n) / 2
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

// merge sort
// class Solution {
// public:
//     double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         int size = n1 + n2;
//         int median = size / 2;
//         int i = 0, j = 0, k = 0;
//         std::vector<int> arr(median + 1);
//         while (i != n1 && j != n2 && i + j <= median) {
//             if (nums1[i] < nums2[j])
//                 arr[k++] = nums1[i++];
//             else
//                 arr[k++] = nums2[j++];
//         }
//         while (i != n1 && i + j <= median) {
//             arr[k++] = nums1[i++];
//         }
//         while (j != n2 && i + j <= median) {
//             arr[k++] = nums2[j++];
//         }
//         return (size % 2 != 0) ? arr[median] : (arr[median - 1] + arr[median]) / 2.0;
//     }
// };
