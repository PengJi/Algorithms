/**
 * 130. 被围绕的区域
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 * 
 * https://leetcode-cn.com/problems/surrounded-regions/
 */

class Solution {
public:
    void solve(vector<vector<char>>& board){
        if(board.empty()) return;
        int row=board.size(), col=board[0].size();

        for(int i = 0; i < row; ++i){
            check(board, i, 0);
            check(board, i, col-1);
        }

        for(int j = 1; j < col - 1; ++j){
            check(board, 0, j);
            check(board, row-1, j);
        }

        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(board[i][j] == 'O') 
                    board[i][j] = 'X';
                else if(board[i][j] == '1') 
                    board[i][j] = 'O';
            }
        }
    }

    void check(vector<vector<char>> & board, int i, int j){
        if(board[i][j] == 'O'){
            board[i][j] = '1';
            if(i > 1) check(board, i-1, j);
            if(j > 1) check(board, i, j-1);
            if(i+1 < board.size()) check(board, i+1, j);
            if(j+1 < board[0].size()) check(board, i, j+1);
        }
    }
};
