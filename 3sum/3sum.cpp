

//  3 sum
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        vector<vector<int> > result;
        for (int i = 0; i < num.size(); ++i) {
            if (i > 0 && num[i] == num[i-1]) {
                continue;
            }
            int x = 0 - num[i];
            int j = i + 1;
            int k = num.size() - 1;
            while (j < k) {
                if (num[j] < x - num[k]) {
                    while (j++ && num[j] == num[j-1]) { ;}
                } else if (num[j] > x - num[k]) {
                    while (k-- && num[k] == num[k+1]) { ;};
                } else {
                    vector<int> r;
                    r.push_back(num[i]);
                    r.push_back(num[j]);
                    r.push_back(num[k]);
                    result.push_back(r);
                    while (j++ && num[j] == num[j-1]) { ;}
                }
            }
        }
        
        return result;
    }
};


int main() 
    return 0;
}
