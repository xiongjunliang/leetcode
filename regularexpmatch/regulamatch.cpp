
//  Regular Expression Match
//  http://leetcode.com/onlinejudge#question_10
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (s == NULL || p == NULL) {
            return false;
        }
        if (*s == '\0' && *p == '\0') {
            return true;
        }
        if (*s == '\0') {
            if (*(p+1) == '*') {
                return isMatch(s, p + 2);
            }
            return false;
        }
        if (*p == '\0') {
            return false;
        }
        if (*p == '.' && *(p+1) != '*') {
            return isMatch(s+1, p+1);
        }
        if (*p == '.' && *(p+1) == '*') {
            const char* s1 = s;
            if (isMatch(s1, p+2)) {
                return true;
            }
            while (*s1 != '\0') {
                if (isMatch(s1+1, p+2)) {
                    return true;
                }
                s1 ++;
            }
        }
        if (*p == *s && *(p+1) != '*') {
            return isMatch(s+1, p+1);
        }
        if (*p == *s && *(p+1) == '*') {
            const char* s1 = s;
            if (isMatch(s1, p+2)) {
                return true;
            }
            while (s1 != '\0' && *s1 == *p) {
                if (isMatch(s1 + 1, p+2)) {
                    return true;
                }
                s1 ++;
            }
        }
        if (*p != *s && *(p+1) == '*') {
            return isMatch(s, p+2);
        }
        return false;
    }
};

int main() {
    Solution s;
    string t;
    string r;
    while (cin >> t >> r) {
        cout << s.isMatch(t.c_str(), r.c_str()) << endl;
    }
    return 0;
}

