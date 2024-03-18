/**
 * 695. 岛屿的最大面积
 * 给定一个包含了一些 0 和 1 的非空二维数组 grid 。
 * 一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，
 * 这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。
 * 你可以假设 grid 的四个边缘都被 0（代表水）包围着。
 * 找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)
 *
 * https://leetcode-cn.com/problems/max-area-of-island/
 */

class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int row = grid.size();
        int col = grid[0].size();

        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ans = max(ans, dfs(grid, i, j));  // 选最大值
            }
        }

        return ans;
    }

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (grid[i][j] == 0) return 0;

        grid[i][j] = 0;  // 访问过的节点设置为0，避免重复访问
        int ans = 1;
        for (int k = 0; k < 4; k++) {  // 遍历四个方向
            int nx = i + dx[k];
            int ny = j + dy[k];

            if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size()) {
                ans += dfs(grid, nx, ny);
            }
        }

        return ans;
    }
};

class Solution {
public:
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

    // flood fill
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j])
                    res = max(res, dfs(i, j, grid));  // 统计最大值
            }
        }

        return res;
    }

    int dfs(int x, int y, vector<vector<int>>& grid) {
        int res = 1;
        grid[x][y] = 0;

        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < grid.size() && b >= 0 && b < grid[0].size() && grid[a][b])
                res += dfs(a, b, grid);  // 统计面积
        }

        return res;
    }
};

class Solution {
public:
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    res = max(res, dfs(i, j, grid));
                }
            }
        }

        return res;
    }

    int dfs(int i, int j, vector<vector<int>>& grid) {
        int res = 1;
        grid[i][j] = 0;

        for (int k = 0; k < 4; k++) {
            int a = i + dx[k], b = j + dy[k];
            if (a >= 0 && a < grid.size() && b >= 0 && b < grid[0].size() &&
                grid[a][b]) {
                res += dfs(a, b, grid);
            }
        }

        return res;
    }
};
