/**
 * 63. 不同路径 II
 * 机器人，网格中有障碍物
 *
 * https://leetcode-cn.com/problems/unique-paths-ii/
 */

class Solution {
public:
    // 动态规划
    // https://leetcode-cn.com/problems/unique-paths-ii/solution/bu-tong-lu-jing-ii-by-leetcode-solution-2/
    // 时间复杂度：O(m * n)
    // 空间复杂度：O(n)
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0) return 0;

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n);
        if (obstacleGrid[0][0] == 0) {
            dp[0] = 1;
        } else {
            dp[0] = 0;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {  // 遇到障碍物
                    dp[j] = 0;
                    continue;
                }

                if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n - 1];
    }

    // https://leetcode-cn.com/problems/unique-paths-ii/solution/jian-dan-dpbi-xu-miao-dong-by-sweetiee/
    int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if (obstacleGrid == null || obstacleGrid.length == 0) {
            return 0;
        }

        // 定义 dp 数组并初始化第 1 行和第 1 列。
        int m = obstacleGrid.length, n = obstacleGrid[0].length;
        int[][] dp = new int[m][n];
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) {
            dp[0][j] = 1;
        }

        // 根据状态转移方程 dp[i][j] = dp[i - 1][j] + dp[i][j - 1] 进行递推。
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
