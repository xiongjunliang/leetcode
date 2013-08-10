
//  InterleavingString
//  http://leetcode.com/onlinejudge#question_97
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<bool> > cache;
        vector<bool> line(s2.length() + 1, true);
        for (int i = 0; i <= s1.length(); ++i) {
            cache.push_back(line);
        }
        return isInterleave(s1, 0, s2, 0, s3, 0, cache); 
    }
    bool isInterleave(string& s1, int index1, string& s2, int index2, 
                string& s3, int index3, vector<vector<bool> >& cache) {
        if (index3 == s3.length() 
                && index1 == s1.length() 
                && index2 == s2.length()) {
            return true;
        } else {
            if (!cache[index1][index2]) {
                return false;
            }
            if (index1 < s1.length() && s3[index3] == s1[index1]) {
                if (isInterleave(s1, index1 + 1, s2, index2, s3, index3 + 1, cache)) {
                    return true;
                }
            }
            if (index2 < s2.length() && s3[index3] == s2[index2]) {
                if (isInterleave(s1, index1, s2, index2 + 1, s3, index3 + 1, cache)) {
                    return true;
                }
            }
        }
        cache[index1][index2] = false;
        return false; 
    }
};

int main() {
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    string s4 = "aadbbbaccc";
    Solution s;
    cout << s.isInterleave(s1, s2, s3) << endl;
    cout << s.isInterleave(s1, s2, s4) << endl;

    return 0;
}
