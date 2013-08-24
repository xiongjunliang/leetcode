
//  Sudoku Solver
//  http://leetcode.com/onlinejudge#question_37
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sudoku(board); 
    }
    bool sudoku(vector<vector<char> >& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (int k = 1; k <=9; ++k) {
                        board[i][j] = '0' + k;
                        if (isvalid(board, i, j) && sudoku(board)) {
                            return true;
                        } 
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isvalid(vector<vector<char> >& board, int x, int y) {
        for (int i = 0; i < 9; ++i) {
            if (i != x && board[i][y] == board[x][y]) {
                return false;
            }
            if (i != y && board[x][i] == board[x][y]) {
                return false;
            }
        }
        for (int i = 3*(x/3); i < 3*((x/3)+1); ++i) {
            for (int j = 3*(y/3); j < 3*((y/3)+1); ++j) {
                if (i != x && j != y && board[i][j] == board[x][y]) {
                    return false;
                }
            } 
        }
        return true;
    }
};


int main() {

    return 0;
}

