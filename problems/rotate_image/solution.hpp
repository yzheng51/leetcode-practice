#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>> &matrix) {
        int n = matrix.size();
        // transpose
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        // reflect
        for (int i = 0; i < n; ++i) {
            for (int j = 0, k = n - 1; j < k; ++j, --k) {
                std::swap(matrix[i][j], matrix[i][k]);
            }
        }
    }
};
