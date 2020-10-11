#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res = {{}};
        dfs(res, nums, {}, 0);
        return res;
    }

private:
    void dfs(vector<vector<int>> &res, vector<int> nums, vector<int> curr, int n) {
        for (int i = n; i < nums.size(); ++i) {
            curr.push_back(nums[i]);
            res.push_back(curr);
            dfs(res, nums, curr, i + 1);
            curr.pop_back();
        }
    }
};
