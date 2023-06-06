/**
 * 2617. 网格图中最少访问的格子数
 * https://leetcode.cn/problems/minimum-number-of-visited-cells-in-a-grid/
*/
class Solution {
public:
    int find(vector<int> &f, int x) {
        return f[x] == x ? x : f[x] = find(f, f[x]);
    }

    // 宽度优先搜索、并查集
    int minimumVisitedCells(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<vector<int>> row(m + 1, vector<int>(n + 1));
        vector<vector<int>> col(n + 1, vector<int>(m + 1));

        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++) {
                row[i][j] = j;
                col[j][i] = i;
            }

        col[0][0] = row[0][0] = 1;

        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));

        vector<vector<int>> d(m, vector<int>(n, -1));
        d[0][0] = 1;

        while (!q.empty()) {
            auto u = q.front();
            q.pop();

            int ux = u.first, uy = u.second;

            for (int j = find(row[ux], uy + 1); 
                j < n && j <= uy + grid[ux][uy]; 
                j = find(row[ux], j + 1)
            ) {
                if (d[ux][j] == -1) {
                    d[ux][j] = d[ux][uy] + 1;
                    q.push(make_pair(ux, j));
                }
                row[ux][j] = find(row[ux], j + 1);
            }

            for (int i = find(col[uy], ux + 1);
                i < m && i <= ux + grid[ux][uy];
                i = find(col[uy], i + 1)
            ) {
                if (d[i][uy] == -1) {
                    d[i][uy] = d[ux][uy] + 1;
                    q.push(make_pair(i, uy));
                }
                col[uy][i] = find(col[uy], i + 1);
            }
        }

        return d[m - 1][n - 1];
    }
};
