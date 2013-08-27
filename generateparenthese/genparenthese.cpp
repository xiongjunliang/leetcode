
//  Generate Parenthese
//  http://leetcode.com/onlinejudge#question_22
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        string s(n*2, ' ');
        dfs(result, s, 0, 0, 0, n);
        return result;
    }
    void dfs(vector<string>& result, string& s, int idx, 
            int left, int right, int n) {
        if (left == n && right == n) {
            result.push_back(s);
            return;
        }
        if (left < n) {
            s[idx] = '(';
            dfs(result, s, idx + 1, left + 1, right, n);
        }
        if (right < left) {
            s[idx] = ')';
            dfs(result, s, idx + 1, left, right + 1, n);
        }
    }
};

int main() {
    int n;
    Solution s;
    while (cin >> n) {
        vector<string> result = s.generateParenthesis(n);
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << endl;
        }
    }
    return 0;
}

