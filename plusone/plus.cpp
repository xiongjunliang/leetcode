

//  Binary Tree Max Path Sum 
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        int mov = 1;
        int i;
        for (i = digits.size() - 1; i >= 0 && mov == 1; i--) {
            digits[i] = digits[i] + mov;
            mov = 0;
            if (digits[i] >= 10) {
                mov = 1;
                digits[i] -= 10;
            }   
        }
        if (mov == 0) {
            return digits;
        } else {
            result.push_back(1);
            for (int j = 0; j < digits.size(); ++j) {
                result.push_back(digits[j]);
            }
            return result;
        }
    }
};

int main() {
    return 0;
}
