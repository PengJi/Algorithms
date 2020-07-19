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
        if(obstacleGrid.size() == 0) return 0;

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n);
        if(obstacleGrid[0][0] == 0) {
            dp[0] = 1;
        } else {
            dp[0] = 0;
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(obstacleGrid[i][j] == 1) {  // 遇到障碍物
                    dp[j] = 0;
                    continue;
                }

                if(j - 1 >= 0 && obstacleGrid[i][j-1] == 0) {
                    dp[j] += dp[j-1];
                }
            }
        }

        return dp[n-1];
    }
};