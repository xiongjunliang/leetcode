

//  Uniq Binary Tree 
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int arr[n + 1];
        memset(arr, 0, sizeof(arr));
        arr[0] = 1;
        arr[1] = 1;
        arr[2] = 2;

        // for i = 3...N
        // for j = 1 ~ i as root NODE 1..j-1 AS LEFT, j+1 ~ i AS right
        for (int i = 3; i <= n; ++i) {
            int j;
            for (j = 1; j <= i/2; ++j) {
                arr[i] += arr[i-j] * arr[j-1] * 2;
            }
            if (i%2 == 1) {
                arr[i] += arr[i-j] * arr[i-j];
            }
        }
        return arr[n];
    }
};

int main()
{
    int n;
    Solution s;
    while (cin >> n) {
        cout << s.numTrees(n) << endl;
    }
}

