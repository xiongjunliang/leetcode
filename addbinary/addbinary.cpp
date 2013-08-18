
//  Add Binary
//  http://leetcode.com/onlinejudge#question_67
//  Author: Xiongjun Liang

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string result;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int f = 0;
        while (1) {
            if (i < 0 && j < 0) {
                break;
            }
            int ia = 0;
            int ib = 0;
            if (i >= 0 && a[i] == '1') {
                ia = 1;
            }
            if (j >= 0 && b[j] == '1') {
                ib = 1;
            }
            int ic = ia + ib + f;
            if (ic >= 2) {
                ic = ic -2;
                f = 1;
            } else {
                f = false;
            }
            result.append(1, '0' + ic);
            i --;
            j --;
        }
        if (f == 1) {
            result.append(1, '1');
        }
        int sz = result.length() - 1;
        for (int i = 0; i <= (sz/2); ++i) {
            char t = result[i];
            result[i] = result[sz - i];
            result[sz -i] = t;
        }
        return result;
    }
};


int main() {
    string a;
    string b;
    Solution s;
    while (cin >> a >> b) {
        cout << s.addBinary(a, b) << endl;
    }
    return 0;
}
