
//  Edit Distance
//  http://leetcode.com/onlinejudge#question_72
//  Author: Xiongjun Liang

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
        return distance(map, word1, 0, word1.length() - 1, 
                word2, 0, word2.length() - 1);
    }
    int distance(vector<vector<int> >& map, string word1, int start1, int end1,
            string word2, int start2, int end2) {
        if (map[start1][start2] != -1) {
            return map[start1][start2];
        }
        if (start1 > end1) {
            if (start2 > end2) {
                return 0;
            } else {
                return end2 - start2 + 1;
            }
        }
        if (start2 > end2) {
            return end1 - start1 + 1;
        }
        if (word1[start1] == word2[start2]) {
            return distance(map, word1, start1 + 1, end1, word2, start2 + 1, end2);
        } else {
            int d1 = distance(map, word1, start1 + 1, end1, word2, start2, end2);
            int d2 = distance(map, word1, start1 + 1, end1, word2, start2 + 1, end2);
            int d3 = distance(map, word1, start1, end1, word2, start2 + 1, end2);
            int ret = min(d1, min(d2, d3)) + 1;
            map[start1][start2] = ret;
            return ret;
        }
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

