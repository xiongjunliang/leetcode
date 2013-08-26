
//  Implement strstr
//  http://leetcode.com/onlinejudge#question_28
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (haystack == NULL || needle == NULL) {
            return NULL;
        }
        vector<int> next(strlen(needle) + 1, -1);
        prepare(needle, next);
        int i = 0;
        int j = 0;
        int idx = 0;
        while (haystack[i] != '\0' && needle[j] != '\0') {
            if (haystack[i] == needle[j]) {
                i ++;
                j ++;
            } else {
                if (j == 0) {
                    i ++;
                    idx = i;
                } else {
                    idx = idx + j - next[j];
                    j = next[j];
                }
            }
        }
        if (needle[j] == '\0') {
            return haystack + idx; 
        }
        return NULL;
    }
    void prepare(char* needle, vector<int>& next) {
        next[0] = -1;
        int i = 0;
        int j = -1;
        while (needle[i] != '\0') {
            if (j == -1 || needle[i] == needle[j]) {
                i ++;
                j ++;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
    }
};

int main() {
    string s;
    string p;
    Solution ss;
    while (cin >> s >> p) {
        cout << ss.strStr((char*)s.c_str(), (char*)p.c_str()) << endl;
    }
    return 0;
}

