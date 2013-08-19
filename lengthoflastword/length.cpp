
//  Length of last word
//  http://leetcode.com/onlinejudge#question_58
//  Author: Xiongjun Liang

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s == NULL) {
            return 0;
        }
        string str(s);
        int len = str.length() - 1;
        while (str[len] == ' ') {
            str.erase(len);
            len --;
        }
        string::size_type r = str.rfind(' ');
        if (r == string::npos) {
            return str.length();
        } else {
            return str.length() - r - 1;
        }
    }
};

int main() {
    string s;
    Solution ss;
    while (getline(cin, s)) {
        cout << ss.lengthOfLastWord(s.c_str()) << endl;
    }
    return 0;
}

