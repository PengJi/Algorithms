/**
 * 5482. 二维网格图中探测环
 * https://leetcode-cn.com/problems/detect-cycles-in-2d-grid/
 */

class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    bool containsCycle(vector<vector<char>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                // 是否已经判断过
                if(grid[i][j] > 0) {
                    if(dfs(grid, i, j, i, j)) return true;
                }   
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>> &G, int x, int y, int lx, int ly) {
        G[x][y] = -G[x][y];
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 排除上一个节点
            if(nx == lx && ny == ly) continue;
            // 超出范围
            if(!(nx >= 0 && nx < G.size() && ny >= 0 && ny < G[0].size())) continue;
            // 搜索到已经遍历过的点，说明成环
            if(G[nx][ny] == G[x][y]) return true;
            // 下一个节点和当前节点不同
            if(G[nx][ny] != -G[x][y]) continue;
            // 判断下一个节点
            if(dfs(G, nx, ny, x, y)) return true;
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
