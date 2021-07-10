/**
 * 79. 单词搜索
 * https://leetcode-cn.com/problems/word-search/
 */

class Solution {
public:
    vector<vector<int>> direction = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    // 回溯法
    // https://leetcode-cn.com/problems/word-search/solution/zai-er-wei-ping-mian-shang-shi-yong-hui-su-fa-pyth/
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        vector<vector<bool>> marked(row, vector<bool>(col, false));

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(dfs(board, word, row, col, i, j, 0, marked)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int row, int col, int i, int j, int start, vector<vector<bool>>& marked) {
        if(start == word.size() - 1) {
            return word[start] == board[i][j];
        }
        
        if(board[i][j] == word[start]) {
            marked[i][j] = true;
            int newi, newj;
            for(int k = 0; k < 4; k++) {
                newi = i + direction[k][0];
                newj = j + direction[k][1];
                if(newi >= 0 && newi < row && newj >= 0 && newj < col && !marked[newi][newj]) {
                    if(dfs(board, word, row, col, newi, newj, start+1, marked)) {
                        return true;
                    }
                }
            }
            marked[i][j] = false;
        }
        return false;
    }
};
