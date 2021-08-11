/**
 * 130. 被围绕的区域
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 * 
 * https://leetcode-cn.com/problems/surrounded-regions/
 */

class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int row = board.size();
        int col = board[0].size();

        // 修改与边相连的节点
        for(int i = 0; i < row; i++) {
            check(board, i, 0);
            check(board, i, col-1);
        }

        // 修改与边相连的节点
        for(int j = 0; j < col; j++) {
            check(board, 0, j);
            check(board, row-1, j);
        }

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '1') board[i][j] = 'O';  // 恢复原值
            }
        }
    }

    void check(vector<vector<char>>& board, int i, int j){
        if(board[i][j] == 'O'){
            board[i][j] = '1';  // 修改一个临时值
            for(int k = 0; k < 4; k++) {  // 遍历四个方向
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size())
                    check(board, nx, ny);
            }
        }
    }
};
