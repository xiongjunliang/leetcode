
//  Word Search  
//  Author: Xiongjun Liang
//  http://leetcode.com/onlinejudge#question_79
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<bool> > map;
        xsz = board.size();
        for (int i = 0; i < board.size(); ++i) {
            vector<bool> x(board[i].size(), false);
            map.push_back(x);
            ysz = board[i].size();
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (dfs(board, word, map, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(const vector<vector<char> >& board, const string& word,
            vector<vector<bool> >& map, int x, int y, int step) {
        if (step == word.length()) {
            return true;
        }
        if (x >= xsz || x < 0 || y >= ysz || y < 0) {
            return false;
        }
        if (board[x][y] == word[step] && !map[x][y]) {
            map[x][y] = true;
            if (dfs(board, word, map, x + 1, y, step + 1)) {
                return true;
            }
            if (dfs(board, word, map, x - 1, y, step + 1)) {
                return true;
            }
            if (dfs(board, word, map, x, y + 1, step + 1)) {
                return true;
            }
            if (dfs(board, word, map, x, y - 1, step + 1)) {
                return true;
            }
            map[x][y] = false;
        }
        return false;
    }
private:
    int xsz;
    int ysz;
};


int main() {
    return 0;
}
