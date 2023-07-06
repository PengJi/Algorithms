/**
 * 2684. 矩阵中移动的最大次数
 * https://leetcode.cn/problems/maximum-number-of-moves-in-a-grid/
*/
class Solution {
public:
    // 动态规划
    int maxMoves(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<int> f(m, 0), g(m, INT_MIN);

        int ans = 0;
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (grid[i][j] > grid[i][j - 1])
                    g[i] = max(g[i], f[i] + 1);

                if (i > 0 && grid[i][j] > grid[i - 1][j - 1])
                    g[i] = max(g[i], f[i - 1] + 1);

                if (i < m - 1 && grid[i][j] > grid[i + 1][j - 1])
                    g[i] = max(g[i], f[i + 1] + 1);
            }

            f = g;
            for (int i = 0; i < m; i++) {
                ans = max(ans, g[i]);
                g[i] = INT_MIN;
            }
        }

        return ans;
    }
};
