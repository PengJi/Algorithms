class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        vector<int> onesRow(m, 0), onesCol(n, 0);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                onesRow[i] += grid[i][j];
                onesCol[j] += grid[i][j];
            }


        vector<vector<int>> res(m, vector<int>(n));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                res[i][j] = 2 * onesRow[i] + 2 * onesCol[j] - m - n;

        return res;
    }
};
