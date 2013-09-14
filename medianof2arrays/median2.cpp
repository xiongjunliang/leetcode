
//  Median of tow sorted array
//  http://leetcode.com/onlinejudge#question_4
//  Author: Xiongjun Liang
//
//  O(LogN) solutions

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int cnt = m + n;
        if (cnt%2 == 1) {
            return findkth(A, m, B, n, cnt/2+1);
        } else {
            return (findkth(A, m, B, n, cnt/2) + 
                    findkth(A, m, B, n, cnt/2+1))/2.0;
        }
    }
    double findkth(int a[], int m, int b[], int n, int k) {
        if (m < n) {
            return findkth(b, n, a, m, k);
        }
        if (n == 0) {
            return a[k-1];
        }
        if (k == 1) {
            return min(a[0], b[0]);
        }
        int pb = min(k/2, n);
        int pa = k - pb;
        if (a[pa-1] < b[pb-1]) {
            return findkth(a+pa, m-pa, b, n, k-pa);
        } else if (a[pa-1] > b[pb-1]) {
            return findkth(a, m, b+pb, n-pb, k-pb);
        } else {
            return a[pa-1];
        }
    }
};

int main() {
    int A[] = {1, 2};
    int B[] = {1, 1};
    Solution s;
    cout << s.findMedianSortedArrays(A, 2, B, 2) << endl;
    return 0;
}


