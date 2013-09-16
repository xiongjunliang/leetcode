

//  Palindrome Partition II
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        vector<int> cnt(len, 0);
        vector<vector<bool> > p(len, vector<bool>(len, false));
        for (int i = 0; i < len; ++i) {
            int j = i;
            int k = i;
            while (j >= 0 && k < len) {
                if (s[j] == s[k]) {
                    p[j][k] = p[k][j] = true;
                } else {
                    break;
                }
                j --;
                k ++;
            }
            j = i - 1;
            k = i;
            while (j >= 0 && k < len) {
                if (s[j] == s[k]) {
                    p[j][k] = p[k][j] = true;
                } else {
                    break;
                }
                j --;
                k ++;
            }
        }
        for (int i = 0; i < len; ++i) {
            if (p[i][0]) {
                cnt[i] = 0;
                continue;
            }
            int min = i;
            for (int j = 1; j <= i; ++j) {
                if (p[i][j]) {
                    if ((cnt[j-1] + 1) < min) {
                        min = cnt[j-1] + 1;
                    }
                }
            }
            cnt[i] = min;
        }
        return cnt[len - 1];
    }
};

int main() {
    string s;
    Solution ss;
    while (cin >> s) {
        cout << ss.minCut(s) << endl;
    }
    return 0;
}
