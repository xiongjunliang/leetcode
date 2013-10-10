

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

        if (word.empty()) {
            return true;
        }
        if (board.empty()) {
            return false;
        }
        int w = board[0].size();
        int h = board.size();
        cout << w << " " << h << endl;
        vector<vector<bool> > used(h, vector<bool>(w, false));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (board[i][j] == word[0]) {
                    used[i][j] = true;
                    if (dfs(board, word, 0, used, i, j)) {
                        return true;
                    }
                    used[i][j] = false;
                }
            }
        }
        return false;

    }
    bool dfs(vector<vector<char> >& board, string word, int idx, 
            vector<vector<bool> >& used, int x, int y) {
        cout << idx << word.length() - 1 << endl;
        if (idx = word.length() - 1) {
            return true;
        }
        if (x > 0 && !used[x-1][y] && board[x-1][y] == word[idx + 1]) {
            used[x-1][y] = true;
            if (dfs(board, word, idx+1, used, x-1, y)) {
                return true;
            }
            used[x-1][y] = false;
        }
        if (x < (board.size()-1) && !used[x+1][y] && board[x+1][y] == word[idx + 1]) {
            used[x+1][y] = true;
            if (dfs(board, word, idx+1, used, x+1, y)) {
                return true;
            }
            used[x+1][y] = false;
        } 
        if (y > 0 && !used[x][y-1] && board[x][y-1] == word[idx + 1]) {
            used[x][y-1] = true;
            if (dfs(board, word, idx+1, used, x, y-1)) {
                return true;
            }
            used[x][y-1] = false;
        } 
        if (y < (board[x].size()-1) && !used[x][y+1] && board[x][y+1] == word[idx + 1]) {
            used[x][y+1] = true;
            if (dfs(board, word, idx+1, used, x, y+1)) {
                return true;
            }
            used[x][y+1] = false;
        } 
        return false;
    }
};

int main() {
    vector<vector<char> > board;
    vector<char> l;
    l.push_back('a');
    board.push_back(l);
    Solution s;
    cout << s.exist(board, "a") << endl;
    return 0;
}
