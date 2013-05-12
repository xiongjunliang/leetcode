


//  Binary Tree Max Path Sum 
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        while (m > 0 || n > 0) {
            if (m > 0 && n > 0) {
                if (A[m-1] > B[n-1]) {
                    A[n+m-1] = A[m-1];
                    m --;
                } else {
                    A[n+m-1] = B[n-1];
                    n--;
                }
            } else if (m > 0) {
                return;
            } else {
                A[n-1] = B[n-1];
                n--;
            }
        
        }   
    }
};

int main() 
{
    return 0;
}

