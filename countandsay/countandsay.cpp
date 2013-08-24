
//  Count and say
//  http://leetcode.com/onlinejudge#question_38
//  Author: Xiongjun Liang
//  题目意思好难理解

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string s = "1";
        for (int i = 2; i <= n; ++i) {
            string ns;
            int cnt = 1;
            char ch = s[0];
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] == ch) {
                    cnt ++;
                } else {
                    ns.append(1, char('0' + cnt));
                    ns.append(1, ch);
                    ch = s[i];
                    cnt = 1;
                }
            }
            ns.append(1, char('0' + cnt));
            ns.append(1, ch);
            s = ns;
        }
        return s;
    }
};

int main() {
    Solution s;
    int x;
    while (cin >> x) {
        cout << s.countAndSay(x) << endl;
    }
    return 0;
}
