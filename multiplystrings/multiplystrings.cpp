
//  MultyplyStrings
//  http://leetcode.com/onlinejudge#question_43
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> n1;
        vector<int> n2;
        for (int i = num1.length() - 1; i >= 0; --i) {
            n1.push_back(num1[i] - '0');
        }
        for (int i = num2.length() - 1; i >= 0; --i) {
            n2.push_back(num2[i] - '0');
        }
        vector<int> res(n1.size() + n2.size(), 0);

        for (int i = 0; i < n1.size(); ++i) {
            for (int j = 0; j < n2.size(); ++j) {
                res[i+j] += n1[i]*n2[j];
                res[i+j+1] += res[i+j]/10;
                res[i+j] = res[i+j]%10;
            }
        }
        int sz = res.size() - 1;
        while (sz >= 0 && res[sz] == 0) {
            sz--;
        }
        if (sz < 0) {
            return "0";
        }
        string ret;
        while (sz >= 0) {
            ret.append(1, res[sz] + '0');
            sz --;
        }
        return ret;
    }
};

int main() {
    string a;
    string b;
    Solution s;
    while (cin >> a >> b) {
        cout << s.multiply(a, b) << endl;
    }
    return 0;
}

