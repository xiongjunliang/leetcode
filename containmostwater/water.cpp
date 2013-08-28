
//  Contain With most water
//  http://leetcode.com/onlinejudge#question_11
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0;
        int right = height.size() - 1;
        int capacity = 0;
        while (left < right) {
            int c = min(height[left], height[right]) * (right - left);
            capacity = max(capacity, c);
            if (height[left] < height[right]) {
                left ++;
            } else {
                right --;
            }
        }
        return capacity;
    }
};

int main() {
    
    return 0;
}

