
//  Remove Duplicates From Sorted Array
//  http://leetcode.com/onlinejudge#question_26
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 1) {
            return n;
        }
        int i = 1; 
        int j = 1;
        for (; j < n; ++j) {
            if (A[j] == A[j-1]) {
                continue;
            } else {
                A[i++] = A[j];
            }
        }
        return i;
    }
};

int main() {
    return 0;
}

