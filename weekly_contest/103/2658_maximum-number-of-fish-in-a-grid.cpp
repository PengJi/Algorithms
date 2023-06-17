/**
 * 2658. 网格图中鱼的最大数目
 * https://leetcode.cn/problems/maximum-number-of-fish-in-a-grid/
*/
class Solution {
public:
    vector<vector<int>> g;
    int n, m;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    int dfs(int x, int y) {
        int v = g[x][y];
        g[x][y] = 0;
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && g[a][b] > 0) {
                v += dfs(a, b);
            }
        }
        return v;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        g = grid;
        n = g.size(), m = g[0].size();

        int res = 0;
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < m; j ++ ) {
                if (g[i][j] > 0) {
                    res = max(res, dfs(i, j));
                }
            }
        }

        return res;
    }
};
