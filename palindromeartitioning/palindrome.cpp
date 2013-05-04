
//  Palindrome Partition I
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > result;
        vector<vector<bool> > map;
        vector<string> road;
        prepare(s, map);
        
        travesal(result, map, road, 0, s, 0);

        return result;
    }

private:
    void travesal(vector<vector<string> >& result, 
                  vector<vector<bool> >& map, 
                  vector<string>& road, int roadi,
                  const string& s, int index) {
        if (index == s.size()) {
            vector<string> road1;
            for (int i = 0; i < roadi; ++i) {
                road1.push_back(road[i]);
            }
            result.push_back(road1);
        }
        for (int i = index; i < s.length(); ++i) {
            if (map[index][i]) {
                if (road.size() > (roadi + 1)) {
                    road[roadi] = s.substr(index, i - index + 1);
                } else {
                    road.push_back(s.substr(index, i - index + 1));
                }
                travesal(result, map, road, roadi + 1, s, i + 1);
            }
        }
    
    }

    void prepare(const string& s, vector<vector<bool> >& map) {
        int length = s.length();
        for (int i = 0; i < length; ++i) {
            map.push_back(vector<bool>(s.length(), false));
        }
        for (int i = 0; i < s.length(); ++i) {
            for (int j = 0;(i - j) >=0 && (i + j) < length; ++j) {
                if (s[i - j] == s[i + j]) {
                    map[i - j][i + j] = true;
                } else {
                    break;
                }
            }
            for (int left = i, right = i + 1; left >= 0 && right < length; left--, right++) {
                if (s[left] == s[right]) {
                    map[left][right] = true;
                } else {
                    break;
                }
            }
        }
    }
};

int main() 
{
    Solution s;
    string str;
    while (cin >> str) {
        vector<vector<string> > result = s.partition(str);
        for (int i = 0; i < result.size(); ++i) {
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

