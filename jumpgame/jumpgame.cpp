
//  Jump Game
//  http://leetcode.com/onlinejudge#question_55
//  Author: Xiongjun Liang

//  Time Limited 
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
        vector<bool> used(n, false);
        jump(used, A, n, 0);
        return used[n-1];
    }
    void jump(vector<bool>& used, int A[], int n, int idx) {
        if (idx < 0 || idx >= n || used[idx]) {
            return;
        }
        used[idx] = true;
        jump(used, A, n, idx + A[idx]);
        jump(used, A, n, idx - A[idx]);
    }
};

int main() {

    return 0;
}
