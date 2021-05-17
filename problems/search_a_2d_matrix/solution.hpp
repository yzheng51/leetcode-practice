#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int left = 0;
        int right = matrix.size() - 1;
        int mid;

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (matrix[mid][0] == target) {
                return true;
            }
            if (matrix[mid].back() < target) {
                left = mid + 1;
            } else if (matrix[mid][0] > target) {
                right = mid - 1;
            } else {
                break;
            }
        }

        left = 0;
        right = matrix[mid].size() - 1;
        int curr = mid;

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (matrix[curr][mid] == target) {
                return true;
            } else if (matrix[curr][mid] < target) {
                left = mid + 1;
            } else if (matrix[curr][mid] > target) {
                right = mid - 1;
            }
        }

        return false;
    }
};

// class Solution {
// public:
//     bool Find(std::vector<std::vector<int>> &array, int target) {
//         if (array.empty() || array[0].empty()) {
//             return false;
//         }
//         int i = 0;
//         int j = array[0].size() - 1;
//         int rows = array.size();

//         while (i < rows && j >= 0) {
//             if (array[i][j] == target) {
//                 return true;
//             } else if (array[i][j] < target) {
//                 ++i;
//             } else if (array[i][j] > target) {
//                 --j;
//             }
//         }
//         return false;
//     }
// };
