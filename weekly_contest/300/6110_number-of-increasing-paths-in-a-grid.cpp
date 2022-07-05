const int N = 1010, MOD = 1e9 + 7;

int f[N][N];

class Solution {
public:
    int n, m;
    vector<vector<int>> g;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    int dp(int x, int y) {
        int& v = f[x][y];
        if (v != -1) return v;

        v = 1;
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && g[a][b] > g[x][y])
                v = (v + dp(a, b)) % MOD;
        }
        return v;
    }

    int countPaths(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        g = grid;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ ) 
                f[i][j] = -1;

        int res = 0;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                res = (res + dp(i, j)) % MOD;
        return res;
    }
};
