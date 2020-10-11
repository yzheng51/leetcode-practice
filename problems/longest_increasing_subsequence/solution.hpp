#include <algorithm>
#include <vector>

class Solution {
public:
    int lengthOfLIS(std::vector<int> &nums) {
        int n = nums.size();
        int res = 0;
        std::vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            res = std::max(res, dp[i]);
        }
        return res;
    }
};
