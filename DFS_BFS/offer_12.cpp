/**
 * 剑指 Offer 12. 矩阵中的路径
 * https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
 */

class Solution {
public:
    // DFS + 剪枝
    // https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/solution/mian-shi-ti-12-ju-zhen-zhong-de-lu-jing-shen-du-yo/
    // 时间复杂度：O(3^k * m * n)
    // 空间复杂度：O(k)
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || board[0].size() == 0) return false;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(dfs(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
        if(i < 0 || i > board.size()-1 || j < 0 || j > board[0].size()-1 || board[i][j] != word[k]) {
            return false;
        }
        if(k == word.size()-1) {
            return true;
        }

        char tmp = board[i][j];
        board[i][j] = '*';  // 设置标志，标识已经遍历
        for(int a = 0; a < 4; a++) {  // 遍历四个方向
            if(dfs(board, word, i+dx[a], j+dy[a], k+1)) return true;
        }
        board[i][j] = tmp;  // 恢复

        return false;
    }
};
