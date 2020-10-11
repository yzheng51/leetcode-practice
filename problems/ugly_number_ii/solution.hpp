#include <algorithm>
#include <vector>

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) {
            return 0;
        }
        std::vector<int> dp(n);
        int t2 = 0, t3 = 0, t5 = 0;
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            dp[i] = std::min(2 * dp[t2], std::min(3 * dp[t3], 5 * dp[t5]));
            if (dp[i] == 2 * dp[t2]) {
                ++t2;
            }
            if (dp[i] == 3 * dp[t3]) {
                ++t3;
            }
            if (dp[i] == 5 * dp[t5]) {
                ++t5;
            }
        }
        return dp[n - 1];
    }
};
