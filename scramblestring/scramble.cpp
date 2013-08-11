
//  Scramble String
//  http://leetcode.com/onlinejudge#question_87
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s1.length() != s2.length()) {
            return false;
        }
        if (s1.length() == 1) {
            return s1[0] == s2[0];
        }
        int cnt1[26] = {0};
        int cnt2[26] = {0};
        for (int i = 0; i < s1.length(); ++i) {
            cnt1[s1[i] - 'a'] += 1;
            cnt2[s2[i] - 'a'] += 1;
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt1[i] != cnt2[i]) {
                return false;
            }
        }
        int len = s1.length();
        for (int mid = 1; mid < len; ++mid) {
            int mid2 = len - mid;
            bool f1 = isScramble(s1.substr(0, mid), s2.substr(0, mid)) 
                && isScramble(s1.substr(mid), s2.substr(mid));
            bool f2 = isScramble(s1.substr(0, mid), s2.substr(mid2))
                && isScramble(s1.substr(mid), s2.substr(0, mid2));
            if (f1 || f2) {
                return true;
            } 
        }
        return false;
    }
};

int main() {
    Solution s;
    string s1;
    string s2;
    while (cin >> s1 >> s2) {
        if (s.isScramble(s1, s2)) {
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }
    return 0;
}

