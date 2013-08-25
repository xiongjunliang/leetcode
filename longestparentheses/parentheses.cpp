
//  Longest valid parentheses
//  http://leetcode.com/onlinejudge#question_32
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct chi {
    char c;
    int i;
    chi(char ch, int idx) : c(ch), i(idx) {}
};

class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.empty()) {
            return 0;
        }
        int len = 0;
        stack<chi> sk;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                sk.push(chi(s[i], i));
            } else if (s[i] == ')') {
                if (!sk.empty() && sk.top().c == '(') {
                    sk.pop();
                    int l;
                    if (sk.empty()) {
                        l = i + 1;
                    } else {
                        l = i - sk.top().i;
                    }
                    len = (l > len) ? l : len;
                } else {
                    sk.push(chi(s[i], i));
                }
            
            }
        }
        return len;
    }
};

int main() {
    string s;
    Solution ss;
    while (cin >> s) {
        cout << ss.longestValidParentheses(s) << endl;
    }
    return 0;
}

