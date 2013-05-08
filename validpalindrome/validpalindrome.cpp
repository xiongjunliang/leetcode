
//  Word Ladder  
//  Author: Xiongjun Liang
//  http://leetcode.com/onlinejudge#question_125
//
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0; 
        int right = s.length() - 1;
        for ( ;left < right; ++left, --right ) {
            char lc = ' '; 
            char rc = ' ';
            for ( ;left <= right; ++left) {
                if (s[left] >= 'A' && s[left] <= 'Z') {
                    lc = s[left] - 'A' + 'a';
                    break;
                } else if ((s[left] >= 'a' && s[left] <= 'z') || 
                        (s[left] >= '0' && s[left] <= '9')) {
                    lc = s[left];
                    break;
                }
            }
            for ( ;left <= right; --right) {
                if (s[right] >= 'A' && s[right] <= 'Z') {
                    rc = s[right] - 'A' + 'a';
                    break;
                } else if ((s[right] >= 'a' && s[right] <= 'z') ||
                       (s[right] >= '0' && s[right] <= '9') ) {
                    rc = s[right];
                    break;
                }
            }
            if (rc != lc) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    
    string s;
    Solution ss;
    while (cin >> s) {
        if (ss.isPalindrome(s)) {
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }

    

    return 0;
}


