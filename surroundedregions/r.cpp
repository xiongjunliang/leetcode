
//
//  Surrounded Regions
//  http://leetcode.com/onlinejudge#question_130
//  Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (board.empty()) {
            return;
        }
        int h = board.size();
        int w = board[0].size();
        for (int i = 0; i < w; ++i) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i);
            }
            if (board[h-1][i] == 'O') {
                dfs(board, h - 1, i);
            }
        }
        for (int i = 0; i < h; ++i) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][w-1] == 'O') {
                dfs(board, i, w - 1);
            }
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'K') {
                    board[i][j] = 'O';
                }
            }
        }

    }
    void dfs(vector<vector<char> >& board, int i, int j) {
        board[i][j] = 'K';
        if (i > 0 && board[i-1][j] == 'O') {
            dfs(board, i - 1, j);
        }
        if (i < (board.size() - 1) && board[i+1][j] == 'O') {
            dfs(board, i + 1, j);
        }
        if (j > 0 && board[i][j-1] == 'O') {
            dfs(board, i, j - 1);
        }
        if (j < (board[i].size() - 1) && board[i][j+1] == 'O') {
            dfs(board, i, j + 1);
        }
    }
};

int main() {
    return 0;

}

