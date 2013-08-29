
//  Palindrome Number
//  http://leetcode.com/onlinejudge#question_9
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int p = 0;
        int y = x;
        while (y > 0) {
            int d = y%10;
            y /= 10;
            p = (p*10);
            p += d;
        }
        return p == x;
    }
};

int main() {
    int n;
    Solution s;
    while (cin >> n) {
        cout << s.isPalindrome(n) << endl;
    }
    return 0;
}

