/**
 * 63. 不同路径 II
 * https://leetcode-cn.com/problems/unique-paths-ii/
 */

class Solution {
public:
    // 动态规划
    // 状态表示：f[i][j] 表示走到节点 obstacleGrid[i][j] 的路径数
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> f(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {  // 不是障碍物
                    if (i == 0 && j == 0)
                        f[j][j] = 1;
                    else if (i == 0)  // 第一行
                        f[i][j] = f[i][j - 1];
                    else if (j == 0)  // 第一列
                        f[i][j] = f[i - 1][j];
                    else
                        f[i][j] = f[i - 1][j] + f[i][j - 1];  // 状态转移
                }
            }
        }

        return f[m - 1][n - 1];
    }
};
