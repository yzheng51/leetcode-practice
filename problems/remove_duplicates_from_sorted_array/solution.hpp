#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        int length = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[length]) {
                nums[++length] = nums[i];
            }
        }
        return ++length;
    }
};
