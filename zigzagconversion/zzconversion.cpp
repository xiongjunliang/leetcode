
//  ZigZag Conversion
//  http://leetcode.com/onlinejudge#question_6
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        vector<string> result;
        for (int i = 0; i < nRows; ++i) {
            result.push_back(string());
        }
        for (size_t i = 0; i < s.length(); ) {
            int j = 0;
            while (j < result.size() && i < s.length()) {
                result[j++].append(1, s[i++]);
            }
            j -= 2;
            while (j > 0 && i < s.length()) {
                result[j--].append(1, s[i++]);
            }
        }
        string ret;
        for (size_t i = 0; i < result.size(); ++i) {
            ret.append(result[i]);
        }
        return ret;
    }
};

int main() {
    string x;
    int n;
    Solution s;
    while (cin >> x >> n) {
        cout << s.convert(x, n) << endl;
    }
    return 0;
}

