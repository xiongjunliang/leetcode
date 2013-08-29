
//  Longest Palindromic Substring
//  http://leetcode.com/onlinejudge#question_5
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.length() <= 1) {
            return s;
        }
        int max_len = 0;
        int left = 0;
        for (int i = 1; i < s.length(); ++i) {
            int len = 0;
            int ml = i - 1;
            int mr = i;
            while (ml >= 0 && mr < s.length() && s[ml] == s[mr]) {
                len = mr - ml + 1;
                ml --;
                mr ++;
            }
            if (len > max_len) {
                max_len = len;
                left = ml + 1;
            }
            len = 1;
            ml = i;
            mr = i;
            while (ml >= 0 && mr < s.length() && s[ml] == s[mr]) {
                len = mr - ml + 1;
                ml --;
                mr ++;
            }
            if (len > max_len) {
                max_len = len;
                left = ml + 1;
            }
        }
        return s.substr(left, max_len);
    }
};

int main() {
    string x;
    Solution s;
    while (cin >> x) {
        cout << s.longestPalindrome(x) << endl;
    }
    return 0;
}

