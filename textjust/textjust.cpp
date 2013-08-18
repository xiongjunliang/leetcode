
//  Text Justification
//  CAREFUL Code Problem
//  http://leetcode.com/onlinejudge#question_68
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        for (int i = 0; i < words.size(); ) {
            string line;
            vector<string> line_words;
            int len = 0;
            int k;
            for (k = i; k < words.size(); ++k) {
                if (len + line_words.size() + words[k].length() <= L) {
                    line_words.push_back(words[k]);
                    len += words[k].length();
                } else {
                    break;
                }
            }
            i = k;
            if (k < words.size()) {
                if (line_words.size() > 1) {
                    int space = (L - len)/line_words.size();
                    int remain = (L - len)%line_words.size();
                    line.append(line_words[0]);
                    line.append(space, ' ');
                    if (remain > 0) {
                        line.append(1, ' ');
                    }
                    remain -= 1;
                    for (int x = 1; x < (line_words.size()-1); ++x) {
                        line.append(line_words[x]);
                        line.append(space, ' ');
                        if (remain > 0) {
                            line.append(1, ' ');
                        }
                        remain -= 1;
                    }
                    if (line_words.size() > 1) {
                        line.append(line_words[line_words.size() - 1]);
                    }
                } else {
                    line.append(line_words[0]);
                    line.append(L-line.size(), ' ');
                }
            } else {
                line.append(line_words[0]);
                for (int x = 1; x < line_words.size(); ++x) {
                    line.append(" ");
                    line.append(line_words[x]);
                }
            }
            result.push_back(line);
        }
        return result;
    }
};

int main() {
    Solution s;
    string ss;
    vector<string> sss;
    while (cin >> ss) {
        sss.push_back(ss);
    }
    vector<string> r = s.fullJustify(sss, 16);
    for (int i = 0; i < r.size(); ++i) {
        cout << r[i] << endl;
    }
    return 0;
}

