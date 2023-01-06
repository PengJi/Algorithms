/**
 * 130. 被围绕的区域
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 * 
 * https://leetcode.cn/problems/surrounded-regions/
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

class Solution {
public:
    vector<vector<bool>> st;
    int n, m;
    
    // 逆向考虑问题
    // 开一个二维布尔数组，记录哪些区域被遍历过。
    // 枚举所有边界上的'O'，从该位置做 Flood Fill，即做深度优先遍历，只遍历是'O'的位置，并将所有遍历到的位置都标记成true。
    // 将所有未遍历到的位置变成'X'。
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i ++ ) {
            vector<bool> temp;
            for (int j = 0; j < m; j ++ )
                temp.push_back(false);
            st.push_back(temp);
        }
        for (int i = 0; i < n; i ++ ) {
            if (board[i][0] == 'O') dfs(i, 0, board);
            if (board[i][m - 1] == 'O') dfs(i, m - 1, board);
        }
        for (int i = 0; i < m; i ++ ) {
            if (board[0][i] == 'O') dfs(0, i, board);
            if (board[n - 1][i] == 'O') dfs(n - 1, i, board);
        }

        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (!st[i][j])
                    board[i][j] = 'X';

    }

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    void dfs(int x, int y, vector<vector<char>>&board) {
        st[x][y] = true;
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && !st[a][b] && board[a][b] == 'O')
                dfs(a, b, board);
        }
    }
};
