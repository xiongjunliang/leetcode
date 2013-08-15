
//  Remove Duplicates
//  http://leetcode.com/onlinejudge#question_80
//  Author: Xiongjun Liang

#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) {
            return 0;
        }
        int cnt = 1;
        int start = 1;
        for (int i = 1; i < n; ++i) {
            if (A[i] == A[i-1]) {
                cnt += 1;
                if (cnt >= 3) {
                    continue;
                }
            } else {
                cnt = 1;
            }
            A[start++] = A[i];
        }
        return start;
    }
};

int main() {
    return 0;
}
