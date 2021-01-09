/**
 * 240. 搜索二维矩阵 II
 * https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/search-a-2d-matrix-ii/solution/sou-suo-er-wei-ju-zhen-ii-by-leetcode-2/
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size()-1;
        int col = 0;

        while(row >= 0 && col < matrix[0].size()) {
            if(matrix[row][col] > target) {
                row--;
            } else if(matrix[row][col] < target) {
                col++;
            } else {
                return true;
            }
        }

        return false;
    }
};
