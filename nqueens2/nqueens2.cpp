
//  N Queens
//  http://leetcode.com/onlinejudge#question_52
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<bool> used(n, false);
        vector<int> list(n, 0);
        int ret = 0;
        dfs(ret, used, list, 0, n);
        return ret;
    }
    void dfs(int& ret, vector<bool> & used, vector<int>& list,
            int row, int n) {
        if (row == n) {
            ret ++;
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (!used[i] && check(list, i, row)) {
                used[i] = true;
                list[row] = i;
                dfs(ret, used, list, row + 1, n);
                used[i] = false;
            }
        }
    }
    bool check(vector<int>& list, int i, int n) {
        for (int k = 0; k < n; ++k) {
            if (abs(n-k) == abs(i - list[k])) {
                return false;
            }
        }
        return true;
    }

};



int main() {
    Solution s;
    int n;
    while (cin >> n) {
        cout << s.totalNQueens(n) << endl;
    }
    return 0;
}

