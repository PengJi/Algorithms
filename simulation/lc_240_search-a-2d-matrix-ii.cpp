/**
 * 240. 搜索二维矩阵 II
 * https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
 */

class Solution {
public:
    // 初始化 up = 0，right = n - 1，从右上角元素开始。
    // 如果发现 matrix[up][right] == target，则直接返回 true；
    // 若 matrix[up][right] < target，则向下移动 up++；
    // 否则，向左移动 right--；
    // 如果出界返回 false。
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();

        int row = 0, col = n - 1;
        while (row < m && col >= 0) {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                row++;
            else
                col--;
        }

        return false;
    }
};

