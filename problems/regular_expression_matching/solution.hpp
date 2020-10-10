#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int n1 = s.size();
        int n2 = p.size();
        std::vector<std::vector<bool>> dp(n1 + 1, std::vector<bool>(n2 + 1));

        // i represent size(s) and j represent size(p)
        // size(p) = 0
        for (int i = 0; i <= n1; ++i) {
            dp[i][0] = (i == 0);
        }
        // size(p) = 1
        for (int i = 0; i <= n1; ++i) {
            dp[i][1] = (i == 1) && (p[0] == s[0] || p[0] == '.');
        }
        // Because main loop includes dp[i-1][]
        // so dp[0][] has to be computed first
        for (int j = 2; j <= n2; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            } else {
                dp[0][j] = false;
            }
        }
        // size(p) > 1
        for (int i = 1; i <= n1; ++i) {
            for (int j = 2; j <= n2; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[i - 1][j];
                } else {
                    dp[i][j] = (p[j - 1] == s[i - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
                }
            }
        }
        return dp[n1][n2];
    }
};
