
//  Jump Game
//  http://leetcode.com/onlinejudge#question_45
//  O(N) algorithm
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int jump(int A[], int n) {    
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 1) {
            return 0;
        }
        int cnt = 0;
        int start = 0;
        int stop = 0;
        int next_stop = 0;
        while (1) {
            for (int i = start; i <= stop; ++i) {
                if ((i + A[i]) > next_stop) {
                    next_stop = i + A[i];
                }
            }
            cnt += 1;
            stop = next_stop;
            if (stop >= (n-1)) {
                break;
            }
        }
        return cnt;
    }
};

int main() {
    int a[] = {2, 3, 1, 1, 4};
    Solution s;
    cout << s.jump(a, 5) << endl;
    return 0;
}
