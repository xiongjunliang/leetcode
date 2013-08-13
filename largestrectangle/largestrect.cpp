
//  Largest Rectangle in Histogram
//  http://leetcode.com/onlinejudge#question_84
//  Author: Xiongjun Liang

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (height.empty()) {
            return 0;
        }
        int max_rect = INT_MIN;
        stack<height_index> hi;
        hi.push(height_index(height[0], 0));
        for (int i = 1; i < height.size(); ++i) {
            height_index hi_top = hi.top();
            int last_pop = 0;
            if (hi_top.height < height[i]) {
                hi.push(height_index(height[i], i));
            } else if (hi_top.height > height[i]) {
                while (!hi.empty()) {
                    height_index hi_top = hi.top();
                    if (hi_top.height > height[i]) {
                        int rect = hi_top.height*(i-hi_top.index);
                        if (rect > max_rect) {
                            max_rect = rect;
                        }
                        last_pop = hi_top.index;
                        hi.pop();
                    } else if (hi_top.height < height[i]) {
                        hi.push(height_index(height[i], last_pop));
                        break;
                    } else {
                        break;
                    }
                }
                if (hi.empty()) {
                    hi.push(height_index(height[i], 0));
                }
            }
        }
        int sz = height.size();
        while (!hi.empty()) {
            height_index hi_top = hi.top();
            int rect =  hi_top.height*(sz-hi_top.index);
            if (rect > max_rect) {
                max_rect = rect;
            }
            hi.pop();
        }
        return max_rect;
    }
private:
    struct height_index {
        int height;
        int index;
        height_index(int h, int i) : height(h), index(i) {}
    };

};

int main() {
    Solution s;
    int x;
    int y;
    while (cin >> x) {
        vector<int> h;
        while (x--) {
            cin >> y;
            h.push_back(y);
        }
        cout << s.largestRectangleArea(h) << endl;
    }
    return 0;
}
