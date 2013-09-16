
//  Longest Consecutive Sequense
//  http://leetcode.com/onlinejudge#question_128
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, node> mapper;
        int max_len = 0;
        for (int i = 0; i < num.size(); ++i) {
            int n = num[i];
            if (mapper.find(n) != mapper.end()) {
                continue;
            }
            map<int, node>::iterator liter = mapper.find(n-1);
            map<int, node>::iterator riter = mapper.find(n+1);
            node d(n);
            if (liter != mapper.end()) {
                d.begin = liter->second.begin;
            }   
            if (riter != mapper.end()) {
                d.end = riter->second.end;
            }
            map<int, node>::iterator iter;
            iter = mapper.find(d.begin);
            if (iter != mapper.end()) {
                iter->second.end = d.end;
            } else {
                mapper.insert(make_pair(d.begin, d));
            }
            iter = mapper.find(d.end);
            if (iter != mapper.end()) {
                iter->second.begin = d.begin;
            } else {
                mapper.insert(make_pair(d.end, d));
            }
            iter = mapper.find(n);
            if (iter != mapper.end()) {
                iter->second.begin = d.begin;
                iter->second.end = d.end;
            } else {
                mapper.insert(make_pair(n, d));
            }

            if ((d.end - d.begin + 1) > max_len) {
                max_len = d.end - d.begin + 1;
            }   
        }   
        return max_len;
    }   
    struct node {
        int begin;
        int end;
        node(int val) : begin(val), end(val) {}
    };  
};


int main() {
    return 0;
}

