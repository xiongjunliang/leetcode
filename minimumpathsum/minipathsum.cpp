
//  Minimum Path Sum
//  http://leetcode.com/onlinejudge#question_64
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (grid.empty()) {
            return 0;
        }
        vector<vector<int> > sum(grid.size(), vector<int>(grid[0].size(), 0));
        sum[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); ++i) {
            sum[i][0] = sum[i-1][0] + grid[i][0];
        }
        for (int i = 1; i < grid[0].size(); ++i) {
            sum[0][i] = sum[0][i-1] + grid[0][i];
        }
        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[i].size(); ++j) {
                sum[i][j] = min(sum[i-1][j], sum[i][j-1]) + grid[i][j];
            }
        }
        return sum[grid.size() - 1][grid[0].size() - 1];
    }
};


int main() { 
    return 0;
}
