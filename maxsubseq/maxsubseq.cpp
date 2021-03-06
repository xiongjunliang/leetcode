
//  Max SubSeq
//  http://leetcode.com/onlinejudge#question_53
//  Author: Xiongjun Liang

#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) {
            return 0;
        }
        int max = A[0];
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += A[i];
            if (sum > max) {
                max = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return max;
    }
};

int main() {
    return 0;
}

