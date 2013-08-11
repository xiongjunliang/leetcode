
//  Max Rectangle
//  http://leetcode.com/onlinejudge#question_85
//  Author: Xiongjun Liang

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.empty()) {
            return 0;
        }
        vector<vector<int> > map;
        for (int i = 0; i < matrix.size(); ++i) {
            vector<int> line(matrix[0].size(), 0);
            map.push_back(line);
        }
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == '1') {
                    if (i > 0) {
                        map[i][j] = map[i-1][j] + 1;
                    } else {
                        map[i][j] = 1;
                    }
                }
            }
        }
        int max_rect = 0; 
        for (int i = 0; i < map.size(); ++i) {
            stack<height_index> hi;
            hi.push(height_index(map[i][0], 0));
            for (int j = 1; j < map[i].size(); ++j) {
                height_index x = hi.top();
                if (map[i][j] > x.height) {
                    hi.push(height_index(map[i][j], j));
                } else if (map[i][j] < x.height) {
                    int last_pop = 0;
                    while (!hi.empty()) {
                        height_index y = hi.top();
                        if (y.height > map[i][j]) {
                            int rect = y.height * (j-y.index);
                            if (rect > max_rect) {
                                max_rect = rect;
                            }
                            last_pop = y.index;
                            hi.pop();
                        } else if (y.height < map[i][j]) {
                            hi.push(height_index(map[i][j], last_pop));
                            break;
                        } else {
                            break;
                        }
                    }
                    if (hi.empty()) {
                        hi.push(height_index(map[i][j], 0));
                    }
                }
            }
            while (!hi.empty()) {
                height_index x = hi.top();
                int rect = x.height * (map[i].size() - x.index);
                if (rect > max_rect) {
                    max_rect = rect;
                }
                hi.pop();
            }
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
    char c;
    int x;
    int y;
    while (cin >> x >> y) {
        vector<vector<char> > martrix;
        while (x--) {
            vector<char> s;
            int z = y;
            while (z--) {
                cin >> c;
                s.push_back(c);
            }
            martrix.push_back(s);
        }
        Solution ss;
        cout << ss.maximalRectangle(martrix) << endl;
    }
    return 0;
}

