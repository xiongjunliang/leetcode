
//  Trapping Rain Water
//  http://leetcode.com/onlinejudge#question_42
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> left(n);
        int leftmax = 0;
        for (int i = 0; i < n; ++i) {
            left[i] = leftmax;
            leftmax = max(leftmax, A[i]);
        }
        vector<int> right(n);
        int rightmax = 0;
        for (int i = n-1; i >= 0; --i) {
            right[i] = rightmax;
            rightmax = max(rightmax, A[i]);
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (min(left[i], right[i]) > A[i]) {
                cnt += min(left[i], right[i]) - A[i];
            }
        }
        return cnt;
    }
};

int main() {
    int a[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution s;
    cout << s.trap(a, 12) << endl;
    return 0;
}

