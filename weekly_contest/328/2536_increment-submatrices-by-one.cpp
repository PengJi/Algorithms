class Solution {
public:
    // 二维差分
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> res(n, vector<int>(n, 0));

        for (const auto &q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            ++res[r1][c1]; 
            if (c2 < n - 1) --res[r1][c2 + 1];
            if (r2 < n - 1) --res[r2 + 1][c1];
            if (c2 < n - 1 && r2 < n - 1) ++res[r2 + 1][c2 + 1];
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (i > 0) res[i][j] += res[i - 1][j];
                if (j > 0) res[i][j] += res[i][j - 1];
                if (i > 0 && j > 0) res[i][j] -= res[i - 1][j - 1];
            }

        return res;
    }
};
