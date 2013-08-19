
//  Insert Interval
//  http://leetcode.com/onlinejudge#question_57
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

//  Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> result;
        int i = 0;
        bool done = false;
        for (i = 0; i < intervals.size(); ++i) {
            if (intervals[i].end < newInterval.start) {
                result.push_back(intervals[i]);
            } else if (intervals[i].start > newInterval.end){
                if (!done) {
                    result.push_back(newInterval);
                    done = true;
                }
                result.push_back(intervals[i]);
            } else {
                done = true;
                Interval x;
                x.start = min(newInterval.start, intervals[i].start);
                x.end = max(newInterval.end, intervals[i].end);
                for (++i; i < intervals.size(); ++i) {
                    if (intervals[i].start > newInterval.end) {
                        result.push_back(x);
                        result.push_back(intervals[i]);
                        break;
                    } else {
                        x.end = max(newInterval.end, intervals[i].end);
                    }
                }
                if (i == intervals.size()) {
                    result.push_back(x);
                }
            }
        }
        if (!done) {
            result.push_back(newInterval);
        }
        return result;
    }
};

int main() {
    return 0;
}

