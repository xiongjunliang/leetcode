
//  3 sum Closest
//  http://leetcode.com/onlinejudge#question_16
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        int min = INT_MAX;
        int sum = 0;
        for (int i = 0; i < num.size(); ++i) {
            if (i > 0 && num[i] == num[i-1]) {
                continue;
            }
            int x = target - num[i];
            int j = i + 1;
            int k = num.size() - 1;
            while (j < k) {
                if (num[j] < x - num[k]) {
                    int q = abs(x - num[k] - num[j]);
                    if (q < min){
                        sum = num[i] + num[k] + num[j];
                        min = q;
                    }
                    while (j++ && num[j] == num[j-1]) { ;}
                } else if (num[j] > x - num[k]) {
                    int q = abs(x - num[k] - num[j]);
                    if (q < min){
                        sum = num[i] + num[k] + num[j];
                        min = q;
                    }
                    while (k-- && num[k] == num[k+1]) { ;};
                } else {
                    return target;
                }
            }
        }
        return min;
    }
};


int main() { 
    return 0;
}
