
//  anagrams
//  http://leetcode.com/onlinejudge#question_49
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, string>& p1, const pair<string, string> p2) {
    return p1.first < p2.first;
}

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        vector<pair<string, string> > str_pairs;
        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            sort(s.begin(), s.end());
            pair<string, string> p = make_pair(s, strs[i]);
            str_pairs.push_back(p);
        }
        sort(str_pairs.begin(), str_pairs.end(), cmp);
        int cnt = 1;
        for (int i = 1; i < str_pairs.size(); ++i) {
            if (str_pairs[i].first == str_pairs[i-1].first) {
                result.push_back(str_pairs[i].second);
                if (cnt == 1) {
                    result.push_back(str_pairs[i-1].second);
                }
                cnt ++;
            } else {
                cnt = 1;
            }
        }
        return result;
    }
};


int main() {

    return 0;
}
