#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        int n = nums.size();
        std::unordered_map<int, int> mp;
        for (int i = 0; i != n; ++i) {
            int curr = nums[i];
            if (mp.count(curr)) {
                return {mp[curr], i};
            } else {
                mp[target - curr] = i;
            }
        }
        return {};
    }
};
