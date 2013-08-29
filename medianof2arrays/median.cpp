
//  Median of tow sorted array
//  http://leetcode.com/onlinejudge#question_4
//  Author: Xiongjun Liang
//
//  Seems it should have O(LogN) solutions
//  deal with it next time

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
        vector<int> merge;
        int i = 0; 
        int j = 0;
        while (i < m && j < n) {
            if (A[i] < B[j]) {
                merge.push_back(A[i]);
                i ++;
            } else {
                merge.push_back(B[j]);
                j ++;
            }
        }
        while (i < m) {
            merge.push_back(A[i]);
            i ++;
        }
        while (j < n) {
            merge.push_back(B[j]);
            j ++;
        }
        size_t len = merge.size();
        if (len%2 == 1) {
            return double(merge[len/2]);
        } else {
            return (double(merge[(len/2)-1]) + double(merge[len/2]))/2;
        }
    }
};

int main() {
    return 0;
}


