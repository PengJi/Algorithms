class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
        const int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

        if (grid[0][0] != 0)
            return false;

        int x = 0, y = 0;
        for (int i = 1; i < n * n; i++) {
            bool ok = false;

            for (int d = 0; d < 8; d++) {
                int tx = x + dx[d], ty = y + dy[d];
                if (tx < 0 || tx >= n || ty < 0 || ty >= n)
                    continue;

                if (grid[tx][ty] == i) {
                    ok = true;
                    x = tx; y = ty;

                    break;
                }
            }

            if (!ok)
                return false;
        }

        return true;
    }
};
