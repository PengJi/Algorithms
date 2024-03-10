/**
 * 64. 最小路径和
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 说明：每次只能向下或者向右移动一步。
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/minimum-path-sum/solution/zui-xiao-lu-jing-he-dong-tai-gui-hua-gui-fan-liu-c/
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

    // 动态规划
    // 时间复杂度：O(m * n)
    // 空间复杂度：O(m)
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;

        int m = grid.size(), n = grid[0].size();
        vector<int> cur(m, grid[0][0]);

        for (int i = 1; i < m; i++)
            cur[i] = cur[i - 1] + grid[i][0];

        for (int j = 1; j < n; j++) {
            cur[0] += grid[0][j];

            for (int i = 1; i < m; i++) {
                cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
            }
        }

        return cur[m - 1];
    }
};
