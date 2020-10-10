#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.empty()) {
            return {};
        }
        int n = intervals.size();
        vector<vector<int>> res;
        std::sort(intervals.begin(), intervals.end(), [](vector<int> x, vector<int> y) { return x[0] < y[0]; });
        res.push_back(intervals[0]);
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] <= res.back()[1]) {
                res.back()[1] = std::max(intervals[i][1], res.back()[1]);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
