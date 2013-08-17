
//  Edit Distance
//  http://leetcode.com/onlinejudge#question_72
//  Author: Xiongjun Liang

// Must USE DP
// USE DFS & CACHE may clause Memory Limit

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > map;
        for (int i = 0; i <= word1.length(); ++i) {
            vector<int> line(word2.length() + 1, -1);
            map.push_back(line);
        }
        map[0][0] = 0;
        for (int i = 1; i <= word1.length(); ++i) {
            map[i][0] = i;
        }
        for (int i = 1; i <= word2.length(); ++i) {
            map[0][i] = i;
        }
        for (int i = 1; i <= word1.length(); ++i) {
            for (int j = 1; j <= word2.length(); ++j) {
                map[i][j] = INT_MAX;
                if (word1[i-1] == word2[j-1]) {
                    map[i][j] = map[i-1][j-1];
                }
                map[i][j] = min(map[i-1][j-1] + 1, map[i][j]);
                map[i][j] = min(map[i][j], min(map[i-1][j] + 1, map[i][j-1] + 1));
            }
        }
        return map[word1.length()][word2.length()];
    }
};

int main () {
    Solution s;
    string s1;
    string s2;
    while (cin >> s1 >> s2) {
        cout << s.minDistance(s1, s2) << endl;
    }
    return 0;
}

