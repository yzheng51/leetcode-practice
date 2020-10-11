#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        dfs(res, n, k, {}, 1);
        return res;
    }

private:
    void dfs(vector<vector<int>> &res, int n, int k, vector<int> curr, int m) {
        if (curr.size() == k) {
            res.push_back(curr);
            return;
        }
        for (int i = m; i <= n; ++i) {
            curr.push_back(i);
            dfs(res, n, k, curr, i + 1);
            curr.pop_back();
        }
    }
};
