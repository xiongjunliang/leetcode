
//  Jump Game
//  http://leetcode.com/onlinejudge#question_55
//  Author: Xiongjun Liang

//
// A Faster way to jump
//
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 1) {
            return true;
        }
        int max = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == 0 && i == max) {
                return false;
            }
            if (A[i] + i > max) {
                max = A[i] + i;
            }
            if (max >= (n - 1)) {
                return true;
            }
        }
        return false;
    }    
};


int main() {

    return 0;
}
