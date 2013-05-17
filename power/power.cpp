class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool flag = false;
        long long m = n;
        if (m == 0) {
            return 1;
        }
        if (m < 0) {
            flag = true;
            m = -m;
        }
        double y = 1.0;
        while (m > 1) {
            if (m%2 == 1) {
                y *= x;
            }
            x *= x;
            m /= 2;
        }
        if (flag) {
            return 1.0/(x*y);
        }
        return x*y;
    }
};
