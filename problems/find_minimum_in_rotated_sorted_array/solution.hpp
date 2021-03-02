#include <vector>

class Solution {
public:
    int findMin(std::vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int res = nums[left];

        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (nums[left] <= nums[mid]) {
                res = std::min(res, nums[left]);
                left = mid + 1;
            } else {
                res = std::min(res, nums[right]);
                right = mid;
            }
        }
        return res;
    }
};
