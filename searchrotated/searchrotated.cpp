
//  Search Rotated Array 
//  http://leetcode.com/onlinejudge#question_33
//  Author: Xiongjun Liang

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Be VERY CAREFUL about all cases
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (A[mid] == target) {
                return mid;
            } else if (A[mid] < target) {
                if (A[right] >= A[mid]) {
                    if (A[right] >= target) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                } else if (A[left] <= A[mid]) {
                    left = mid + 1;
                }
            } else {
                if (A[left] <= A[mid] && A[left] <= target) {
                    right = mid - 1;
                } else if (A[right] >= A[mid]){
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }

            }
        }
        return -1;
    }
};

int main() {
    int a[] = {4, 5, 6, 7, 8, 1, 2, 3};
    Solution s;
    int x;
    while (cin>>x) {
        cout << s.search(a, 8, 8) << endl;
    }
    return 0;
}


