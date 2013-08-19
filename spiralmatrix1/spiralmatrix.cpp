
//  Spiral Matrix
//  http://leetcode.com/onlinejudge#question_59
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.empty()) {
            return vector<int>();
        }
        vector<int> result; 
        int beginx = 0;
        int endx = matrix[0].size() - 1;
        int beginy = 0;
        int endy = matrix.size() - 1;
        while (1) {
            int x = beginx;
            while (x <= endx) {
                result.push_back(matrix[beginy][x]);
                x++;
            }
            beginy++;
            if (beginy > endy) {
                break;
            }
            int y = beginy;
            while (y <= endy) {
                result.push_back(matrix[y][endx]);
                y++;
            }
            endx --;
            if (endx < beginx) {
                break;
            }
            int rx = endx;
            while (rx >= beginx) {
                result.push_back(matrix[endy][rx]);
                rx --;
            }
            endy --;
            if (endy < beginy) {
                break;
            }
            int ry = endy;
            while (ry >= beginy) {
                result.push_back(matrix[ry][beginx]);
                ry --;
            }
            beginx ++;
            if (beginx > endx) {
                break;
            }
        }
        return result;
         
    }
};



int main() {
    int n;
    Solution s;
    vector<vector<int> > matrix;
    vector<int> line;
    line.push_back(1);
    line.push_back(2);
    line.push_back(3);
    matrix.push_back(line);
    line[0] += 3;
    line[1] += 3;
    line[2] += 3;
    matrix.push_back(line);
    line[0] += 3;
    line[1] += 3;
    line[2] += 3;
    matrix.push_back(line);
    vector<int> result = s.spiralOrder(matrix);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

