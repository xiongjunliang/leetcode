
//  Search Insert Position
//  http://leetcode.com/onlinejudge#question_35
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) {
            return 0;
        }
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] == target) {
                return mid;
            } else if (A[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main() {
    Solution s;
    int a[] = {1, 3, 5, 6};
    cout << s.searchInsert(a, 4, 5) << endl;
    cout << s.searchInsert(a, 4, 2) << endl;
    cout << s.searchInsert(a, 4, 7) << endl;
    cout << s.searchInsert(a, 4, 0) << endl;
    return 0;
}

