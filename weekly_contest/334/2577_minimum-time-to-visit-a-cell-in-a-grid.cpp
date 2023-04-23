const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

class Solution {
private:
    int m, n;

    int check(int t, const vector<vector<int>> &grid) {
        if (t < grid[m - 1][n - 1])
            return false;

        vector<vector<int>> d(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        q.push(make_pair(m - 1, n - 1));

        d[m - 1][n - 1] = t;

        while (!q.empty()) {
            auto u = q.front();
            q.pop();

            if (u.first == 0 && u.second == 0)
                return true;

            if (d[u.first][u.second] == 0)
                continue;

            for (int i = 0; i < 4; i++) {
                int vx = u.first + dx[i], vy = u.second + dy[i];

                if (vx < 0 || vx >= m || vy < 0 || vy >= n)
                    continue;

                if (grid[vx][vy] > d[u.first][u.second] - 1)
                    continue;

                if (d[vx][vy] == -1) {
                    d[vx][vy] = d[u.first][u.second] - 1;
                    q.push(make_pair(vx, vy));
                }
            }
        }

        return false;
    }

public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        m = grid.size(); n = grid[0].size();

        int t = (m + n) % 2;

        int l = 0, r = 100010;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(2 * mid + t, grid)) r = mid;
            else l = mid + 1;
        }

        return 2 * l + t;
    }
};
