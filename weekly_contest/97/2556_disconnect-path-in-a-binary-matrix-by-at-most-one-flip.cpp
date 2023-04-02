class Solution {
private:
    int m, n;

    bool find(int x, int y, vector<vector<int>> &g) {
        if (x >= m || y >= n)
            return false;

        if (g[x][y] == 0 && !((x == 0 && y == 0) || (x == m - 1 && y == n - 1)))
            return false;

        g[x][y] = 0;

        if (x == m - 1 && y == n - 1)
            return true;

        return find(x + 1, y, g) || find(x, y + 1, g);
    }

public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();

        return !find(0, 0, grid) || !find(0, 0, grid);
    }
};
