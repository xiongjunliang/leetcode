
//  Letter Combine of phone numbers
//  http://leetcode.com/onlinejudge#question_17
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        vector<string> dict;
        dict.push_back(" ");
        dict.push_back(",");
        dict.push_back("abc");
        dict.push_back("def");
        dict.push_back("ghi");
        dict.push_back("jkl");
        dict.push_back("mno");
        dict.push_back("pqrs");
        dict.push_back("tuv");
        dict.push_back("wxyz");

        string line(digits.length(), ' ');
        dfs(result, dict, line, digits, 0);
        return result;
    }
    void dfs(vector<string>& result, vector<string>& dict,
            string& line, string& digits, int idx) {
        if (idx == digits.length()) {
            result.push_back(line);
            return;
        }
        int n = digits[idx] - '0';
        for (size_t i = 0; i < dict[n].length(); ++i) {
            line[idx] = dict[n][i];
            dfs(result, dict, line, digits, idx + 1);
        }
    }
};

int main() {
    string s;
    Solution ss;
    while (cin >> s) {
        vector<string> r = ss.letterCombinations(s);
        for (size_t i = 0; i < r.size(); ++i) {
            cout << r[i] << endl;
        }
    }
    return 0;
}

