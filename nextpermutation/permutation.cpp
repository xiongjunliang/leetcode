
//  Next Permutation
//  http://leetcode.com/onlinejudge#question_32
//  Author: Xiongjun Liang

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.empty() || num.size() == 1) {
            return;
        }
        int i = num.size() - 2;
        for (;i >= 0; i--) {
            if (num[i] < num[i+1]) {
                break;
            }
        }
        if (i >= 0) {
            int k = i + 1;
            for (;k < num.size(); ++k) {
                if (num[k] <= num[i]) {
                    break;
                }
            }
            k = k - 1;
            int tmp = num[i];
            num[i] = num[k];
            num[k] = tmp;
            sort(num.begin() + i + 1, num.end());
        } else {
            sort(num.begin(), num.end());
            if (num[0] == 0) {
                for (int i = 0; i < num.size(); ++i) {
                    if (num[i] != 0) {
                        num[0] = num[i];
                        num[i] = 0;
                        break;
                    }
                }
            }
        }
        return; 
    }
};

int main() {
    vector<int> num;
    num.push_back(3);
    num.push_back(2);
    num.push_back(1);
    num.push_back(0);
    num.push_back(0);
    Solution s;
    s.nextPermutation(num);
    for (int i = 0; i < num.size(); ++i) {
        cout << num[i] << " ";
    }
    cout << endl;
    return 0;
}
