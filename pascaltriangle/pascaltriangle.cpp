

//  Triangle Leetcode
//  Link http://leetcode.com/onlinejudge#question_118
//  Author: Xiongjun Liang

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        for (int i = 1; i <= numRows; ++i) {
            vector<int> line;
            line.push_back(1);
            for (int j = 1; j < (i+1)/2; ++j) {
                line.push_back(result[i-2][j] + result[i-2][j-1]);
            }
            for (int k = (i/2) - 1; k >= 0; k--) {
                line.push_back(line[k]);
            }
            result.push_back(line);
        }
        return result;
    }
};

int main() {
    Solution s;
    int n;
    while (cin >> n) {
        vector<vector<int> > ret = s.generate(n);
        for (int i = 0; i < ret.size(); ++i) {
            for (int j = 0; j < ret[i].size(); ++j) {
                cout << ret[i][j] << " ";
            }
            cout << endl;
        } 
    }
    return 0;
}
