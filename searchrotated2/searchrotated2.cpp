
//  Search Rotated Array II 
//  http://leetcode.com/onlinejudge#question_81
//  Author: Xiongjun Liang

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Be VERY CAREFUL about all cases
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (A[mid] == target) {
                return true;
            } 
            if (A[mid] < A[right]) {
                if (A[mid] < target && A[right] >= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else if (A[left] < A[mid]) {
                if (A[left] <= target && A[mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (A[mid] == A[left]) {
                left ++;
            } else if (A[right] == A[mid]) {
                right --;
            }
        }
        return false;
    }
};

int main() {
    int a[] = {1, 1, 3, 1};
    Solution s;
    int x;
    while (cin>>x) {
        cout << s.search(a, 4, x) << endl;
    }
    return 0;
}


