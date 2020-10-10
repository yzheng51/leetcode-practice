class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1 / x;
        }
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        double half = myPow(x, abs(n / 2));
        return (n % 2 == 0) ? half * half : half * half * x;
    }
};
