/**
 * 73. 矩阵置零
 * https://leetcode-cn.com/problems/set-matrix-zeroes/
 */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        bool row0 = false, col0 = false;

        // 第一行是否有零
        for(int j = 0; j < col; j++) {
            if(matrix[0][j] == 0) {
                row0 = true;
                break;
            }
        }

        // 第一列是否有零
        for(int i = 0; i < row; i++) {
            if(matrix[i][0] == 0) {
                col0 = true;
                break;
            }
        }

        // 把第一行第一列作为标志位
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        // 将矩阵置0
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // 将第 0 行置 0
        if(row0) {
            for(int j = 0; j < col; j++) {
                matrix[0][j] = 0;
            }
        }
        // 将第 0 列置 0
        if(col0) {
            for(int i = 0; i < row; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
