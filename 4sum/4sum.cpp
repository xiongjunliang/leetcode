
//  4 sum
//  http://leetcode.com/onlinejudge#question_18
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        vector<vector<int> > result;
        for (int i = 0; i < num.size(); ++i) {
            if (i > 0 && num[i] == num[i-1]) {
                continue;
            }
            int l = i + 1;
            for (; l < num.size(); ++l) {
                if (l > (i+1) && num[l] == num[l-1]) {
                    continue;
                }   
                int x = target - num[i] - num[l];
                int j = l + 1;
                int k = num.size() - 1;
                while (j < k) {
                    if (num[j] < x - num[k]) {
                        while (j++ && num[j] == num[j-1]) { ;}
                    } else if (num[j] > x - num[k]) {
                        while (k-- && num[k] == num[k+1]) { ;};
                    } else {
                        vector<int> r;
                        r.push_back(num[i]);
                        r.push_back(num[l]);
                        r.push_back(num[j]);
                        r.push_back(num[k]);
                        result.push_back(r);
                        
                        while (j++ && num[j] == num[j-1]) { ;}
                    }
                }
            }
        }
        return result;
    }
};


int main() { 
    vector<int> num; //1 0 -1 0 -2 2
    num.push_back(1);
    num.push_back(0);
    num.push_back(-1);
    num.push_back(0);
    num.push_back(-2);
    num.push_back(2);
    Solution s;
    vector<vector<int> > r = s.fourSum(num, 0);
    for (size_t i = 0; i < r.size(); ++i) {
        for (size_t j = 0; j < r[i].size(); ++j) {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
