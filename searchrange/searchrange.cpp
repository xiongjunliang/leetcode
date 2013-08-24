
//  Search for a range
//  http://leetcode.com/onlinejudge#question_34
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if (n <= 0) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        int l;
        int r;
        int left = 0; 
        int right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        l = left;
        left = 0; 
        right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        r = right;
        if (l > r) {
            ret.push_back(-1);
            ret.push_back(-1);
        } else {
            ret.push_back(l);
            ret.push_back(r);
        }
        return ret;
    }
};

int main() {
    return 0;
}
