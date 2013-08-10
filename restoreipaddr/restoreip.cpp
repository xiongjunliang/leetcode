
//  Restore IP ADDR
//  http://leetcode.com/onlinejudge#question_93
//  Author: Xiongjun Liang

//  NOT a diffcult problem, 
//  but it is really difficult to write bug free code


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result; 
        restoreip(s, 0, 0, result);
        return result;
    }
    void restoreip(string s, int index, int ip_count, vector<string>& result) {
        if (ip_count > 0) {
            s.insert(index, 1, '.');
            index ++;
        }
        if (ip_count == 3) {
            string s1 = s.substr(index);
            int num = atoi(s1.c_str());
            if (s1.length() == 3 && num < 256 && num > 99) {
                result.push_back(s);
            } else if (s1.length() == 2 && num > 9) {
                result.push_back(s);
            } else if (s1.length() == 1) {
                result.push_back(s);
            }
        } else {
            if (s.length() > index) {
                string s1 = s.substr(index, 1);
                int num = atoi(s1.c_str());
                restoreip(s, index + 1, ip_count + 1, result); 
            } 
            if (s.length() > index + 1) {
                string s1 = s.substr(index, 2);
                int num = atoi(s1.c_str());
                if (num > 9) {
                    restoreip(s, index + 2, ip_count + 1, result); 
                }
            } 
            if (s.length() > index + 3) {
                string s1 = s.substr(index, 3);
                int num = atoi(s1.c_str());
                if (num < 256 && num > 99) {
                    restoreip(s, index + 3, ip_count + 1, result); 
                } 
            }
        }
    }
};

int main() 
{
    Solution s;
    vector<string> result;
    string ss;
    while (cin>>ss) {
        result = s.restoreIpAddresses(ss);
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << endl;
        }
    }

    return 0;
}
