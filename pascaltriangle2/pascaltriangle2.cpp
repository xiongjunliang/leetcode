

//  Triangle Leetcode
//  Link http://leetcode.com/onlinejudge#question_119
//  Author: Xiongjun Liang

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        vector<int> result1(rowIndex + 1, 0);
        result.push_back(result1);
        result.push_back(result1);
        int index = 0;
        for (int i = 1; i <= (rowIndex + 1); ++i) {
            result[index][0] = 1;
            int j = 1;
            for (j = 1; j < (i+1)/2; ++j) {
                result[index][j] = 
                    result[(index+1)%2][j] + result[(index+1)%2][j-1];
            }
            for (int k = (i/2) - 1; k >= 0; k--, j++) {
                result[index][j] = result[index][k];
            }
            index = (index + 1)%2;
        }
        return result[(index+1)%2];
    }
};

int main() {
    Solution s;
    int n;
    while (cin >> n) {
        vector<int> ret = s.getRow(n);
        for (int i = 0; i < ret.size(); ++i) {
                cout << ret[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
