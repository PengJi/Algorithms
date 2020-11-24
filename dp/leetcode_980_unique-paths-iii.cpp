/**
 * 980. 不同路径 III
 * https://leetcode-cn.com/problems/unique-paths-iii/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/unique-paths-iii/solution/dfs-hui-su-shuang-bai-by-quantum-10/
    int uniquePathsIII(vector<vector<int>>& grid) {
        int start_x = 0, start_y = 0, step_num = 1;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    start_y = i;
                    start_x = j;
                    continue;
                }
                if(grid[i][j] == 0) step_num++;
            }
        }

        return dfs(start_x, start_y, step_num, grid);
    }

    int dfs(int x, int y, int step_cur, vector<vector<int>>& grid) {
        //排除越界的情况和遇到障碍的情况
        if(x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size() || grid[y][x] == -1) 
            return 0;
        if(grid[y][x] == 2) return step_cur == 0 ? 1 : 0;
        grid[y][x] = -1;  //已走过的标记为障碍
        int res = 0;
        res += dfs(x - 1, y, step_cur - 1, grid);
        res += dfs(x + 1, y, step_cur - 1, grid);
        res += dfs(x, y - 1, step_cur - 1, grid);
        res += dfs(x, y + 1, step_cur - 1, grid);
        grid[y][x] = 0;  //dfs遍历完该位置为起始位置的情况后，置零，以不影响后面的dfs
        return res; 
    }
};
