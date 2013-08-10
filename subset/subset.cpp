
//  SubSet
//  http://leetcode.com/onlinejudge#question_78
//  Author: Xiongjun Liang

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        vector<bool> used(S.size(), false);
        vector<int> list;
        sort(S.begin(), S.end());
        dfs(ret, used, S, list, 0);
        return ret;
    }
    void dfs(vector<vector<int> >& ret, vector<bool>& used,
            vector<int>& s, vector<int> list, int index) {
        ret.push_back(list); 
        if (list.size() == s.size()) {
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            used[i] = true;
            vector<int> x = list;
            x.push_back(s[i]);
            dfs(ret, used, s, x, i + 1);
            used[i] = false;
        }
    }
};

int main() {
    vector<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    
    Solution ss;
    vector<vector<int> > ret = ss.subsets(s);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
