
//  String To Integer 
//  http://leetcode.com/onlinejudge#question_8
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int64_t num = 0;
        int neg = 1;
        while (*str == ' ') {
            str ++;
        }
        if (*str == '-') {
            neg *= -1;
            str ++;
        }
        if (*str == '+') {
            str ++;
        }
        while (*str != '\0' && *str >= '0' && *str <= '9') {
            num = num*10 + (*str - '0');
            str ++;
        }
        num = num * neg;
        if (num < INT_MIN) {
            return INT_MIN;
        }
        if (num > INT_MAX) {
            return INT_MAX;
        }
        return num;
    }
};

int main() {
    return 0;
}

