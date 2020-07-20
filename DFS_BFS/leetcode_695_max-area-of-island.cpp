/**
 * 695. 岛屿的最大面积
 * 
 * https://leetcode-cn.com/problems/max-area-of-island/
 */

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++) 
            for(int j = 0; j < grid[0].size(); j++)
                res = max(res, dfs(grid, i, j));

        return res;
    }

private:
    int ci[4] = {0, 0, 1, -1}, cj[4] = {1, -1, 0, 0};
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] != 1)
            return 0;

        grid[i][j] = 0;  // 访问过的节点设置为0，避免重复访问

        int ans = 1;
        int next_i, next_j;
        // 遍历四个方向
        for(int idx = 0; idx < 4; idx++) {
            next_i = i + ci[idx];
            next_j = j + cj[idx];
            ans += dfs(grid, next_i, next_j);
        }

        return ans;
    }
};
