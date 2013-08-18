
//  Simplify Path
//  http://leetcode.com/onlinejudge#question_71
//  Author: Xiongjun Liang
//  Be VERY careful about any cases

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<string> st;
        int start = 0;
        int end = 0;
        for (int i = 0; i < path.length(); ++i) {
            if (path[i] != '/') {
                start = i;
                break;
            }
        }
        for (int i = start; i < path.length(); ++i) {
            if (path[i] == '/' || i == (path.length() - 1)) {
                string str;
                if (path[i] == '/') {
                    str = path.substr(start, i - start);
                } else {
                    str = path.substr(start, i - start + 1);
                }
                start = i + 1;
                if (str == "" || str == ".") {
                    continue;
                } else if (str == "..") {
                    if (!st.empty()) {
                        st.pop();
                    } 
                } else {
                    st.push(str);
                }
                if (i == (path.length() - 1)) {
                    break;
                }
            } 
        }
        vector<string> output;
        while (!st.empty()) {
            output.push_back(st.top());
            st.pop();
        }
        string ret;
        for (int i = output.size() - 1; i >= 0; i--) {
            ret += "/" + output[i];
        }
        if (ret == "") {
            return "/";
        }
        return ret;
    }
};

int main() {
    Solution s;
    string ss;
    while (cin >> ss) {
        cout << s.simplifyPath(ss) << endl;
    }
    return 0;
}

