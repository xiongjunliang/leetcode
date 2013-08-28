
//  Roman to Integer
//  http://leetcode.com/onlinejudge#question_13
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] == 'M') {
                ret += 1000;
            } else if (s[i] == 'D') {
                ret += 500;
            } else if (s[i] == 'C') {
                if ((i + 1) < s.length() && s[i+1] == 'D') {
                    ret += 400;
                    ++i;
                    continue;
                } else if ((i + 1) < s.length() && s[i+1] == 'M') {
                    ret += 900;
                    ++i;
                } else {
                    ret += 100;
                }
            } else if (s[i] == 'L') {
                ret += 50;
            } else if (s[i] == 'X') {
                if ((i + 1) < s.length() && s[i+1] == 'L') {
                    ret += 40;
                    ++i;
                    continue;
                } else if ((i + 1) < s.length() && s[i+1] == 'C') {
                    ret += 90;
                    ++i;
                } else {
                    ret += 10;
                }
            } else if (s[i] == 'V') {
                ret += 5;
            } else if (s[i] == 'I') {
                if ((i + 1) < s.length() && s[i+1] == 'V') {
                    ret += 4;
                    ++i;
                    continue;
                } else if ((i + 1) < s.length() && s[i+1] == 'X') {
                    ret += 9;
                    ++i;
                } else {
                    ret += 1;
                }
            }
        }
        return ret;
    }
};

int main() {
    string s;
    Solution ss;
    while (cin >> s) {
        cout << ss.romanToInt(s) << endl;
    }
    return 0; 
}
