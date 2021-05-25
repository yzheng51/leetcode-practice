#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int min_price = prices[0];
        int max_profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            min_price = std::min(prices[i], min_price);
            max_profit = std::max(max_profit, prices[i] - min_price);
        }
        return max_profit;
    }
};
