#include <algorithm>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int> &height) {
        int i = 0;
        int j = height.size() - 1;
        int area = 0;
        while (i != j) {
            if (height[i] < height[j]) {
                area = std::max(area, height[i] * (j - i));
                ++i;
            } else {
                area = std::max(area, height[j] * (j - i));
                --j;
            }
        }
        return area;
    }
};
