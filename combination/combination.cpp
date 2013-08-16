
//  Combination
//  http://leetcode.com/onlinejudge#question_77
//  Author: Xiongjun Liang

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        vector<bool> used(n, false);
        vector<int> line(k, 0);
        for (int i = 1; i <= n; ++i) {
            dfs(result, used, 0, i, n, k, line);
        }
        return result;
    }

    void dfs(vector<vector<int> >& result, vector<bool>& used, 
            int index, int x, int n, int k, vector<int>& line) {
        line[index] = x;
        index = index + 1;
        if (index == k) {
            result.push_back(line);
            return;
        }
        used[x] = true;
        for (int i = x+1; i <=n; ++i) {
            if (!used[i]) {
                dfs(result, used, index, i, n, k, line);
            }
        }
        used[x] = false;

    }
};

int main() {
    Solution s;
    vector<vector<int> > result = s.combine(4, 2);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

