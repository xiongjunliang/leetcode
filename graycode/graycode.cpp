
//  GrayCode
//  http://leetcode.com/onlinejudge#question_89
//  Author: Xiongjun Liang

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        if (n < 0) {
            return result;
        }
        if (n == 0) {
            result.push_back(0);
            return result;
        }
        int levvel_idx = 2;
        result.push_back(0);
        result.push_back(1);
        for (int i = 2; i <= n; ++i) {
            int sss = 1 << (i-1); 
            for (int j = levvel_idx - 1; j >= 0; --j) {
                result.push_back(sss | result[j]);
            }
            levvel_idx = result.size();
        }
        return result;
    }
};

int main() {
    Solution s;
    int x;
    while (cin>>x) {
        vector<int> ret = s.grayCode(x);
        for (int i = 0; i < ret.size(); ++i) {
            cout << ret[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

