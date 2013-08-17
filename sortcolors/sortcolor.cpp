
//  Sort colors 
//  Author: Xiongjun Liang

#include <iostream>

class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int num[3] = {0};
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; ++i) {
            num[A[i]] ++;
        }
        int index = 0;
        for (int j = 0; j < 3; ++j) {
            for (int i = 0; i < num[j]; ++i) {
                A[index++] = j;
            }
        }
    }
};

int main() {
    return 0;
}
