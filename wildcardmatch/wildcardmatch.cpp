
//  Wild Card Match
//  http://leetcode.com/onlinejudge#question_44
//  Author: Xiongjun Liang
//  CAN ONLY PASS (JUDGE SMALL)

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
            if (*p == '*') {
                return isMatch(s, p + 1);
            }
            return false;
        }
        if (*p == '\0') {
            return false;
        }
        if (*p == '?') {
            return isMatch(s+1, p+1);
        }
        if (*p == '*') {
            while (*(p+1) == '*') {
                p++;
            }
            const char* s1 = s;
            const char* p1 = p + 1;
            if (*p1 == '\0') {
                return true;
            }
            while (*s1 != '\0') {
                if (isMatch(s1, p1)) {
                    return true;
                }
                s1 ++;
            } 
        }
        if (*p == *s) {
            return isMatch(s+1, p+1);
        }
        return false;
    }
};

int main() {
    string a;
    string b;
    Solution s;
    while (cin >> a >> b) {
        cout << s.isMatch(a.c_str(), b.c_str());
    }
    return 0; 
}
