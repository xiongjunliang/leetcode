
//  Palindrome Partition I
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (S.empty() || T.empty()) {
            return 0;
        }
        vector<vector<int> > dp;
        vector<int> line(S.length(), 0);
        for (int i = 0; i < T.length(); ++i) {
            dp.push_back(line);
        }
        if (S[0] == T[0]) {
            dp[0][0] = 1;
        }
        for (int i = 1; i < S.length(); ++i) {
            if (S[i] == T[0]) {
                dp[0][i] = dp[0][i-1] + 1;
            } else {
                dp[0][i] = dp[0][i-1];
            }
        }
        for (int i = 1; i < T.length(); ++i) {
            for (int j = i; j < S.length(); ++j) {
                if (S[j] == T[i]) {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[T.length()-1][S.length()-1];
    }
};

int main() 
{
    Solution s;
    cout << s.numDistinct("ddd", "dd") << endl;
    return 0;
}

