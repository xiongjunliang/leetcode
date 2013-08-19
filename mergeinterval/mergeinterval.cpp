
//  Merge Interval
//  http://leetcode.com/onlinejudge#question_56
//  Author: Xiongjun Liang
//
//  Holy SHIT !!!
//  the given intervals was not SORTED by start

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//  Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(const Interval& left, const Interval& right) {
    return left.start < right.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> result;
        if (intervals.empty()) {
            return result;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        result.push_back(intervals[0]);
        for (int i = 1, j = 0; i < intervals.size(); ++i) {
            if (intervals[i].start <= result[j].end) {
                result[j].end = max(intervals[i].end, result[j].end);
                if (intervals[i].start < result[j].start) {
                    result[j].start = intervals[i].start;
                }
            } else {
                result.push_back(intervals[i]);
                ++j;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}

