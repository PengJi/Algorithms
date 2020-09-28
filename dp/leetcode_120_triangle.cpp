/**
 * 120. 三角形最小路径和
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
 */

class Solution {
public:
    // 动态规划
    // https://leetcode-cn.com/problems/triangle/solution/di-gui-ji-yi-hua-dp-bi-xu-miao-dong-by-sweetiee/
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(n)
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        if(row == 0) return 0;

        vector<int> dp(row+1, 0);
        for(int i = row-1; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }

        return dp[0];
    }

    // 动态规划
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(n^2)
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        if(row == 0) return 0;

        // dp[i][j] 表示从点 (i, j) 到底边的最小路径和。
        vector<vector<int>> dp(row+1, vector<int>(row+1, 0));
        // 三角形的最后一行开始递推
        for(int i = row - 1; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
            }
        }

        return dp[0][0];
    }
};
