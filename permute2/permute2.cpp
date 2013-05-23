
//  permute
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        vector<vector<int> > result;
        vector<int> path;
        path.resize(num.size());
        vector<bool> visited(num.size(), false);
        for (int i = 0; i < num.size(); ++i) {
            visit(result, num, path, visited, 0, i);
        }
        return result;
    } 
private:
    void visit(vector<vector<int> >& result, 
            vector<int>& num, vector<int>& path, 
            vector<bool>& visited, int index, int current) {
        visited[current] = true;
        path[index] = num[current];
        if (index + 1 == num.size()) {
            result.push_back(path);
        }
        for (int i = 0; i <  num.size(); ++i) {
            if (!visited[i]) {
                if (i > 0 && num[i] == num[i-1] && visited[i-1]) {
                    continue;
                }
                visit(result, num, path, visited, index + 1, i);
            }
        }
        visited[current] = false;
    }

};

int main() 
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    Solution s;
    vector<vector<int> > result = s.permuteUnique(v);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[0].size(); ++j) {
            cout << result[i][j];
        }
        cout << endl;
    }
    return 0;
}
