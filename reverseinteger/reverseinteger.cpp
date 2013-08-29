
//  Reverse Integer
//  http://leetcode.com/onlinejudge#question_7
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int neg = 1;
        int64_t x64 = x;
        int64_t y64 = 0;
        if (x64 < 0) {
            x64 = -x64;
            neg *= -1;
        }
        while (x64 > 0) {
            int d = x64%10;
            y64 = y64 * 10 + d;
            x64 /= 10;
        }
        y64 *= neg;
        if (y64 < INT_MIN) {
            return INT_MIN;
        }
        if (y64 > INT_MAX) {
            return INT_MAX;
        }
        return y64;
    }
};

int main() {
    return 0;
}

