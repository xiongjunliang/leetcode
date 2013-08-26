
//  Divide two Integers
//  http://leetcode.com/onlinejudge#question_29
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int64_t dend64 = dividend;
        int64_t visor64 = divisor;
        int neg = 1;
        if (dend64 < 0) {
            dend64 = 0 - dend64;
            neg *= -1;
        }
        if (divisor < 0) {
            visor64 = 0 - visor64;
            neg *= -1;
        }
        if (visor64 == 1) {
            return dend64*neg;
        }
        if (visor64 == 2) {
            return (dend64 >> 1) * neg;
        }
        int ret = 0;
        int64_t d = visor64;
        int power = 1;
        int64_t remain = dend64;
        while (remain >= visor64) {
            while (remain > (2*d)) {
                d *= 2;
                power *= 2;
            }
            while (remain < d) {
                d /= 2;
                power /= 2;
            }
            remain -= d;
            ret += power;
        }
        return ret*neg;
    }
};

int main() {
    Solution s;
    int a;
    int b;
    while (cin >> a >> b) {
        cout << s.divide(a, b) << endl;
    }
    return 0;
}

