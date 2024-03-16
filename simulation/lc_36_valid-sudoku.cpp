/**
 * 36. 有效的数独
 * https://leetcode-cn.com/problems/valid-sudoku/description/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/valid-sudoku/solution/36-jiu-an-zhao-cong-zuo-wang-you-cong-shang-wang-x/
    bool isValidSudoku(vector<vector<char>>& board) {
        // 哈希表存储每一行的每个数是否出现过，默认初始情况下，每一行每一个数都没有出现过
        // 整个board有9行，第二维的维数10是为了让下标有9，和数独中的数字9对应。
        vector<vector<int>> row(9, vector<int>(10, 0));
        // 存储每一列的每个数是否出现过，默认初始情况下，每一列的每一个数都没有出现过
        vector<vector<int>> col(9, vector<int>(10, 0));
        // 存储每一个box的每个数是否出现过，默认初始情况下，在每个box中，每个数都没有出现过。整个board有9个box。
        vector<vector<int>> box(9, vector<int>(10, 0));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int cur = board[i][j] - '0';
                if (row[i][cur]) return false;
                if (col[j][cur]) return false;
                if (box[j / 3 + (i / 3) * 3][cur]) return false;

                row[i][cur] = 1;
                col[j][cur] = 1;
                box[j / 3 + (i / 3) * 3][cur] = 1;
            }
        }

        return true;
    }
};
