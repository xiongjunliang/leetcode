
//
//  Surrounded Regions
//  Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char> >& board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(board.empty()) {
            return; 
        }
        for (int i = 0; i < board[0].size(); ++i) {
            if (board[0][i] == 'O') {
                travesal(board, 0, i);
            }
            if (board[i][0] == 'O') {
                travesal(board, i, 0);
            }
        }
        int y = board.size() - 1;
        for (int i = 0; i < board[y].size(); ++i) {
            if (board[y][i] == 'O') {
                travesal(board, y, i);
            }
            if (board[i][y] == 'O') {
                travesal(board, i, y);
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; 
                }
                if (board[i][j] == 'A') {
                    board[i][j] = 'O'; 
                }
            }
        }
    }

    void travesal(vector<vector<char> >& board, int x, int y) {
        board[x][y] = 'A';
        if (x > 0 && board[x - 1][y] == 'O') {
            travesal(board, x - 1, y);
        }
        if (x < (board.size() - 1) && board[x + 1][y] == 'O') {
            travesal(board, x + 1, y);
        }
        
        if (y > 0 && board[x][y - 1] == 'O') {
            travesal(board, x, y - 1);
        }
        if (y < (board[x].size() - 1) && board[x][y + 1] == 'O') {
            travesal(board, x, y + 1);
        }
    }
};


int main() 
{
    Solution s;
    int x;
    char c;
    while (cin >> x) {
        vector<vector<char> > board;
        for (int i = 0; i < x; ++i) {
            vector<char> str;
            for (int j = 0; j < x; ++j) {
                cin >> c;
                str.push_back(c);
            }
            board.push_back(str);
        } 
        s.solve(board);
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < x; ++j) {
                cout << board[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}

