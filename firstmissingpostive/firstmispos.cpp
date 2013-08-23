
//  First Missing Postive
//  http://leetcode.com/onlinejudge#question_41
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) {
            return 0;
        }
        for (int i = 0; i < n;) {
            for (int j = 0; j < n; ++j) {
                cout << A[j] << " ";
            }
            cout << endl;
            if (A[i] == i) {
                i++;
                continue;
            } 
            if (A[i] >= 0 && A[i] < n && A[A[i]] != A[i]) {
                int t = A[i];
                A[i] = A[A[i]];
                A[t] = t;
                continue;
            } else {
                i++;
            }
        }
        for (int i = 1; i < n; ++i) {
            if (A[i] != i) {
                return i;
            }
        }
        return A[0] == n ? (n+1):n;
    }
};

int main() {
    int a[] = {1, 0};
    Solution s;
    cout << s.firstMissingPositive(a, 2) << endl;
    return 0;
}
