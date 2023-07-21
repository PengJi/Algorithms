/**
 * 2713. 矩阵中严格递增的单元格数
 * https://leetcode.cn/problems/maximum-strictly-increasing-cells-in-a-matrix/description/
*/

#define PII pair<int, int>
#define X first
#define Y second

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        const int m = mat.size(), n = mat[0].size();

        vector<PII> p(m * n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                p[i * n + j] = make_pair(i, j);

        sort(p.begin(), p.end(), [&](const PII &a, const PII &b) {
            return mat[a.X][a.Y] > mat[b.X][b.Y];
        });

        vector<int> f(m * n, 0);
        vector<int> r(m, 0), c(n, 0);
        int ans = 1;

        f[0] = 1;
        for (int i = 1, j = 0; i < m * n; i++) {
            if (mat[p[j].X][p[j].Y] > mat[p[i].X][p[i].Y]) {
                while (j < i) {
                    r[p[j].X] = max(r[p[j].X], f[j]);
                    c[p[j].Y] = max(c[p[j].Y], f[j]);

                    ++j;
                }
            }

            f[i] = max(r[p[i].X], c[p[i].Y]) + 1;
            ans = max(ans, f[i]);
        }

        return ans;
    }
};
