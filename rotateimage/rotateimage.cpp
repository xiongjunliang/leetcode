
//  Rotate Image
//  http://leetcode.com/onlinejudge#question_48
//  Author: Xiongjun Liang

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.empty()) {
            return;
        }
        int left = 0;
        int up = 0;
        int right = matrix.size() - 1;
        int down = matrix.size() - 1;
        while (up < down && left < right) {
            for (int i = 0; i < (right-left); ++i) {
                int reserve = matrix[up][left+i];
                matrix[up][left+i] = matrix[down-i][left];
                matrix[down-i][left] = matrix[down][right-i];
                matrix[down][right-i] = matrix[up+i][right];
                matrix[up+i][right] = reserve;
            } 
            left ++;
            up ++;
            right --;
            down --;
        }
        return;
    }
};

int main() {
    vector<vector<int> > matrix;
    vector<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    matrix.push_back(l1);
    vector<int> l2;
    l2.push_back(4);
    l2.push_back(3);
    matrix.push_back(l2);
    Solution s;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] <<  " ";
        }
        cout << endl;
    }
    s.rotate(matrix);
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] <<  " ";
        }
        cout << endl;
    }
    return 0;
}
