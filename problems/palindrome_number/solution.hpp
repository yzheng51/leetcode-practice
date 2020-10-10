class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int res = 0, cnt = 1;
        for (int y = x / 10; y != 0; y /= 10) {
            cnt *= 10;
        }

        for (int y = x; y != 0; y /= 10, cnt /= 10) {
            res = 10 * res + y % 10;
            if (res != x / cnt) {
                return false;
            }
        }
        return res == x;
    }
};
