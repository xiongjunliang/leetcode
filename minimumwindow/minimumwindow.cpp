
//  Minimum Window
//  http://leetcode.com/onlinejudge#question_76
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (S.empty() || T.empty()) {
            return "";
        }
        string ret = "";
        int left = 0;
        int len = INT_MAX;
        int count = T.length();
        int cntT[256];
        int cntS[256];
        memset(cntT, 0, sizeof(cntT));
        memset(cntS, 0, sizeof(cntS));
        for (int i = 0; i < T.length(); ++i) {
            cntT[T[i]] ++;
            cntS[T[i]] ++;
        }
        for (int right = 0; right < S.length(); ++right) {
            if (cntT[S[right]] > 0) {
                cntS[S[right]] --;
                if (cntS[S[right]] >= 0) {
                    count --;
                }
            }
            if (count == 0) {
                int x = 0;
                for (x = left; x < S.length(); x++) {
                    if (cntT[S[x]] > 0) {
                        cntS[S[x]] ++;
                        if (cntS[S[x]] > 0) {
                            count ++;
                            break;
                        }
                    }
                }
                left = x + 1;
                int l = right - x + 1;
                if (l < len) {
                    len = l;
                    ret = S.substr(x, l);
                }
            }
        }
        return ret;
    }
};

int main() {
    string s;
    string t;
    Solution ss;
    while (cin >> s >> t) {
        cout << ss.minWindow(s, t) << endl;
    }
    return 0;
}

