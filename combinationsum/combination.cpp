
//  Combination Sum
//  http://leetcode.com/onlinejudge#question_39
//  Author: Xiongjun Liang

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {    
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        vector<int> line;
        sort(candidates.begin(), candidates.end());
        dfs(result, line, candidates, 0, 0, target);
        return result;
    }

    void dfs(vector<vector<int> >& result, vector<int>& line, 
            vector<int>& candidates, int start, int idx, int target) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            vector<int> l ;
            for (int i = 0; i < idx; ++i) {
                l.push_back(line[i]);
            }
            result.push_back(l);
        } else {
            for (int i = start; i < candidates.size(); ++i) {
                if (line.size() == idx) {
                    line.push_back(candidates[i]);
                } else {
                    line[idx] = candidates[i];
                }
                dfs(result, line, candidates, i, idx + 1, target - candidates[i]);
            }
        }


    }
};

int main() {
    Solution s;
    vector<int> candidates;
    candidates.push_back(7);
    candidates.push_back(3);
    candidates.push_back(6);
    candidates.push_back(2);
    vector<vector<int> > result = s.combinationSum(candidates, 7);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

