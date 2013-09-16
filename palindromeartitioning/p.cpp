
//  Palindrome Partition I
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<string> > partition(string s) {
        int len = s.length();
        vector<vector<bool> > map(len, vector<bool>(len, false));
        make_map(s, map);
        vector<vector<string> > ret;
        vector<string> line;
        line.resize(len);
        dfs(map, ret, line, s, 0, 0, len);
        return ret;
    }
    
    void dfs(vector<vector<bool> >& map, vector<vector<string> >& ret, 
            vector<string>& line, string& s, int l, int idx, int len) {
        if (idx == len) {
            vector<string> x;
            for (int i = 0; i < l; ++i) {
                x.push_back(line[i]);
            }
            ret.push_back(x);
            return;
        }
        for (int j = idx; j < len; ++j) {
            if (map[idx][j]) {
                line[l] = s.substr(idx, j - idx + 1);
                dfs(map, ret, line, s, l+1, j+1, len);
            }
        }
    }

    void make_map(string& s, vector<vector<bool> >& map) {
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            int j = i;
            int k = i;
            while (j >= 0 && k < len) {
                if (s[j] == s[k]) {
                    map[j][k] = map[k][j] = true;
                } else {
                    break;
                }
                j --;
                k ++;
            }
            j = i - 1;
            k = i;
            while (j >= 0 && k < len) {
                if (s[j] == s[k]) {
                    map[j][k] = map[k][j] = true;
                } else {
                    break;
                }
                j --;
                k ++;
            }
        }
    }
};


int main() {
    string s;
    Solution x;
    while (cin >> s) {
        vector<vector<string> > ret = x.partition(s);
        for (int i = 0; i < ret.size(); ++i) {
            for (int j = 0; j < ret[i].size(); ++j) {
                cout << ret[i][j] << " ";
            }
        }
    }
    return 0;
}
