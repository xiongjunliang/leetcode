

//  Palindrome Partition I
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>

using namespace std;

class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x == 0) {
            return 0;
        }
        
        int beign = 0;
        int end = x/2 < std::sqrt(INT_MAX)? x/2 + 1 : std::sqrt(INT_MAX);
        while (beign <= end) {
            int mid = (beign + end) / 2;
            int sq = mid * mid;
            if (sq == x) {
                return mid;
            }
            if (sq < x) {
                beign = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return (beign + end) / 2;
    }
};

int main() {
    Solution s;
    int x;
    while (cin >> x) {
        cout << s.sqrt(x) << endl;
    }
    return 0;
}

