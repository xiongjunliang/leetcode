
//  Triangle Leetcode
//  Link http://leetcode.com/onlinejudge#question_120
//  Author: Xiongjun Liang

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sz = triangle.size();
        for (int i = 1; i < triangle.size(); ++i) {
            triangle[i][0] += triangle[i-1][0];
            for (int j = 1; j < i; ++j) {
                int p = min(triangle[i-1][j-1], triangle[i-1][j]);
                triangle[i][j] += p;
            } 
            triangle[i][i] += triangle[i-1][i-1];   
        }
        int min = INT_MAX;
        for (int i = 0; i < sz; ++i) {
            if (triangle[sz-1][i] < min) {
                min = triangle[sz-1][i];
            }
        }
        return min;
    }
};

int main() 
{
    Solution s;
    vector<vector<int> > triangle;
    vector<int> x;
    //
    x.push_back(2);
    triangle.push_back(x);
    x.clear();
    //
    x.push_back(3);
    x.push_back(4);
    triangle.push_back(x);
    x.clear();
    //
    x.push_back(6);
    x.push_back(5);
    x.push_back(7);
    triangle.push_back(x);
    x.clear();
    //
    x.push_back(4);
    x.push_back(1);
    x.push_back(8);
    x.push_back(3);
    triangle.push_back(x);
    x.clear();
    
    for (int i = 0; i < triangle.size(); ++i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            cout << triangle[i][j];
        }
        cout << endl;
    }
    
    cout << s.minimumTotal(triangle) << endl;
    
    for (int i = 0; i < triangle.size(); ++i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    } 
    return 0;
}
