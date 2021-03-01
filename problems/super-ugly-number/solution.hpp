#include <vector>

class Solution {
public:
    int nthSuperUglyNumber(int n, std::vector<int> &primes) {
        int n_primes = primes.size();
        std::vector<int> counter(n_primes, 0);
        std::vector<int> dp(n);

        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            int temp = INT_MAX;
            for (int j = 0; j < n_primes; ++j) {
                temp = std::min(temp, primes[j] * dp[counter[j]]);
            }
            dp[i] = temp;
            for (int j = 0; j < n_primes; ++j) {
                if (dp[i] == primes[j] * dp[counter[j]]) {
                    ++counter[j];
                }
            }
        }
        return dp[n - 1];
    }
};
