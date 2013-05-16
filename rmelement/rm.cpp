


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
    int removeElement(int A[], int n, int elem) {
        int i, j;
        for (i = 0, j = -1; i < n; ++i) {
            if (A[i] == elem) {
                continue;
            }
            j++;
            A[j] = A[i];
        }
        return (j+1);
    }


};

int main() {
    return 0;
}

