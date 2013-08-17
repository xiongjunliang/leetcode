
//  Search 2D Martrix
//  O(M+N) wroks 
//  use Binary Search O(LOG(M+N))
//  http://leetcode.com/onlinejudge#question_74
//  Author: Xiongjun Liang

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, 
            int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.empty()) {
            return false;
        }
        int i = 0;
        for (i = 0; i < matrix.size(); ++i) {
            if (matrix[i][0] > target) {
                break;
            }
        }
        if (i == 0) {
            return false;
        }
        i --;
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                return false;
            }
        }
        return false;
    }
};

int main() {
    return 0;
}


