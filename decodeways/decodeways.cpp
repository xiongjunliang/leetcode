
//  Decode Ways
//  http://leetcode.com/onlinejudge#question_91
//  Author: Xiongjun Liang
//
//  BE very careful about special CASE 

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.empty() || s[0] == '0') { // DEAL with num starts from '0'
            return 0;
        } else if (s.length() == 1) {
            return 1;
        }
        vector<int> num(s.length(), 0); 
        num[0] = 1;
        string s1 = s.substr(0, 2); 
        int n = atoi(s1.c_str());
        if (s[1] != '0') { // 0
            num[1] += 1;
        }
        if (n <= 26 && n >= 10) { // Less than 10??
            num[1] += 1;
        } 
        for (int i = 2; i < s.length(); ++i) {
            if (s[i] != '0') {
                num[i] += num[i-1];
            }
            string s1 = s.substr(i-1, 2); 
            int n = atoi(s1.c_str());
            if (n <= 26 && n >= 10) {
                num[i] += num[i-2];
            }
        }
        return num[s.length()-1];
    }
};



int main() 
{
    Solution s;
    string ss;
    while (cin >> ss) {
        cout << s.numDecodings(ss) << endl;
    }
    return 0;
}


