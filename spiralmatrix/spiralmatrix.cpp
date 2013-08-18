
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
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) {
            return vector<vector<int> >();
        }
        vector<vector<int> >  result(n, vector<int>(n)); 
        int beginx = 0;
        int endx = n - 1;
        int beginy = 0;
        int endy = n - 1;
        int cur = 1;
        while (1) {
            int x = beginx;
            while (x <= endx) {
                result[beginy][x++] = cur++;
            }
            beginy++;
            if (beginy > endy) {
                break;
            }
            int y = beginy;
            while (y <= endy) {
                result[y++][endx] = cur++;
            }
            endx --;
            if (endx < beginx) {
                break;
            }
            int rx = endx;
            while (rx >= beginx) {
                result[endy][rx--] = cur++;
            }
            endy --;
            if (endy < beginy) {
                break;
            }
            int ry = endy;
            while (ry >= beginy) {
                result[ry--][beginx] = cur++;
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
    while (cin >> n) {
        vector<vector<int> > result = s.generateMatrix(n);
        for (int i = 0; i < result.size(); ++i) {
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

