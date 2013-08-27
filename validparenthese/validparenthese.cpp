
//  Valid Parenthese
//  http://leetcode.com/onlinejudge#question_20
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> sk;
        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] == '('
                    || s[i] == '['
                    || s[i] == '{') {
                sk.push(s[i]);
            } else {
                if (sk.empty()) {
                    return false;
                }
                char ch = sk.top();
                if (ch == '(' && s[i] == ')') {
                    sk.pop();
                    continue;
                } else if (ch == '[' && s[i] == ']') {
                    sk.pop();
                    continue;
                } else if (ch == '{' && s[i] == '}') {
                    sk.pop();
                    continue;
                }
                return false;
            }
        }
        if (sk.empty()) {
            return true;
        }
        return false;
    }
};

int main() {
    string s;
    Solution ss;
    while (cin >> s) {
        cout << ss.isValid(s) << endl;
    }
    return 0;
}
