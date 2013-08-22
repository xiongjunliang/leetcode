
//  Wild Card Match
//  http://leetcode.com/onlinejudge#question_44
//  Author: Xiongjun Liang

//  PASS LARDGE
//  使用DP来加速
//  只能使用两行BOOL数组，否则会超内存
//  使用长度剪枝才能通过大数据

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
        if (s == NULL && p == NULL) {
            return true;
        }
        if (s == NULL || p == NULL) {
            return false;
        }
        const char* s1 = s;
        int lens = 1;
        while (*s1 != '\0') {
            lens ++;
            s1++;
        }
        string pp;
        const char* p1 = p;
        int lenp = 1;
        int lenpp = 1;
        while (*p1 != '\0') {
            lenp ++;
            if (*p1 != '*') {
                lenpp ++;
            }
            p1++;
        }
        if (lens < lenpp) { 
            return false;
        }
        vector<vector<bool> > map(2, vector<bool>(lens, false));
        map[0][0] = true;
        for (int i = 1; i < lenp; ++i) {
            int idx = i%2;
            int ridx = (i-1)%2;
            for (int x = 0; x < lens; ++x) {
                map[idx][x] = false;
            }
            if (p[i-1] == '?') {
                for (int j = 1; j < lens; ++j) {
                    if (map[ridx][j-1]) {
                        map[idx][j] = true;
                    }
                }
            } else if (p[i-1] == '*') {
                int j = 1;
                for (j = 0; j < lens; ++j) {
                    if(map[ridx][j]) {
                        break;
                    }
                }
                if (j < lens) {
                    for (int k = j; k < lens; ++k) {
                        map[idx][k] = true;
                    }
                }
            } else {
                for (int j = 1; j < lens; ++j) {
                    if (map[ridx][j-1] && p[i-1] == s[j-1]) {
                        map[idx][j] = true;
                    }
                }
            } 
        }
        /* 
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < lens; ++j) {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
        */
        return map[(lenp-1)%2][lens-1];
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
