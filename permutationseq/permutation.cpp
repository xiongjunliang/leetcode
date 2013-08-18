
//  Permutation Sequence
//  http://leetcode.com/onlinejudge#question_60
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        kth = 0;
        for (int i = 1; i <= n; ++i) {
            used[i] = false;
        }
        ret = "";
        dfs(n, k, 0);
        return ret;
    }
    void dfs(int n, int k, int index) {
        if (index == n) {
            kth ++;
            if (kth == k) {
                for (int i = 0; i < n; ++i) {
                    ret.append(1, '0' + tmp[i]);
                }
            }
            return;
        }
        if (kth >= k) {
            return;
        }
       
        for (int i = 1; i <= n; ++i) {
            if (!used[i]) {
                used[i] = true;
                tmp[index] = i;
                dfs(n, k, index + 1);
                used[i] = false;
            }
        } 
    }
private:
    int kth;
    bool used[11];
    int tmp[11];
    string ret;
};

int main() {
    Solution s;
    int n;
    int k;
    while (cin >> n >> k) {
        cout << s.getPermutation(n, k) << endl;
    }
    return 0;
}
