
//  N Queens
//  http://leetcode.com/onlinejudge#question_51
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<bool> used(n, false);
        vector<int> list(n, 0);
        vector<vector<string> > ret;
        dfs(ret, used, list, 0, n);
        return ret;
    }
    void dfs(vector<vector<string> >& ret, vector<bool> & used, vector<int>& list,
            int row, int n) {
        if (row == n) {
            vector<string> r;
            for (int i = 0; i < n; ++i) {
                string s;
                int j = 0;
                for(j = 0; j < list[i]; ++j) {
                    s.append(1, '.');
                }
                s.append(1, 'Q');
                for (++j;j < n; ++j) {
                    s.append(1, '.');
                }
                r.push_back(s);
            }
            ret.push_back(r);
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
    vector<vector<string> > ret = s.solveNQueens(4);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            cout << ret[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}

