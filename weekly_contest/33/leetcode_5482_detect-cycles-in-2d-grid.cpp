/**
 * 5482. 二维网格图中探测环
 * https://leetcode-cn.com/problems/detect-cycles-in-2d-grid/
 */

class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    bool containsCycle(vector<vector<char>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0)  {
                    if (dfs(grid, i, j, i, j)) return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>> &G, int x, int y, int lx, int ly) {
        G[x][y] = -G[x][y];
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];

            if (tx == lx && ty == ly) 
              continue;

           if (!(0 <= tx && tx < G.size() && 0 <= ty && ty < G[0].size())) 
               continue;

           if (G[tx][ty] == G[x][y]) 
               return true;

           if (G[tx][ty] != -G[x][y]) 
               continue;

           if (dfs(G, tx, ty, x, y)) 
               return true;
        }

        return false;
    }
};

class Solution {
public:
    vector<vector<char>> g;
    vector<vector<bool>> vi;
    vector<vector<int>> dd = { {0,1}, {0,-1}, {1,0}, {-1,0} };

    // https://leetcode-cn.com/problems/detect-cycles-in-2d-grid/solution/detect-cycles-in-2d-grid-by-ikaruga/
    bool containsCycle(vector<vector<char>>& grid) {
        g = grid;
        vi = vector<vector<bool>>(g.size(), vector<bool>(g[0].size(), false));

        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[i].size(); j++) {
                if (g[i][j] == '.') continue;
                if (dfs(g[i][j], i, j, -1, -1)) return true;
            }
        }
        return false;
    }

    bool dfs(char c, int x, int y, int px, int py) {
        if (x < 0 || x >= g.size() || y < 0 || y >= g[0].size()) return false;
        if (g[x][y] != c) return false;
        if (vi[x][y]) return true;
        vi[x][y] = true;
        for (auto d : dd) {
            int dx = x + d[0];
            int dy = y + d[1];
            if (dx == px && dy == py) continue;
            if (dfs(c, dx, dy, x, y)) return true;
        }
        vi[x][y] = false;
        g[x][y] = '.';
        return false;
    }
};
