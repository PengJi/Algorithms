/**
 * 64. 最小路径和
 * https://leetcode-cn.com/problems/minimum-path-sum/
 */

class Solution {
public:
    // 动态规划
    // 状态表示：grid[i][j] 表示走到节点 [i,j] 的最短距离
    // 原地修改数组
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;
                else if (i == 0)
                    grid[i][j] = grid[i][j - 1] + grid[i][j];
                else if (j == 0)
                    grid[i][j] = grid[i - 1][j] + grid[i][j];
                else
                    grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
            }
        }

        return grid[m - 1][n - 1];
    }
};

class Solution {
public:
    // 动态规划
    // 状态表示：f[i][j] 表示走到节点 [i,j] 的最短距离
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> f(m, vector<int>(n, INT_MAX));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    f[i][j] = grid[i][j];
                else if (i == 0)
                    f[i][j] = f[i][j - 1] + grid[i][j];
                else if (j == 0)
                    f[i][j] = f[i - 1][j] + grid[i][j];
                else
                    f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
            }

        return f[m - 1][n - 1];
    }
};
