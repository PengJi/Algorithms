/**
 * 2812. 找出最安全路径
 * https://leetcode.cn/problems/find-the-safest-path-in-a-grid/description/
*/
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

const int N = 410;

class Solution {
private:
    int n, d[N][N];
    bool v[N][N];
    queue<int> q;

    void bfs(const vector<vector<int>> &grid) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                d[i][j] = INT_MAX;

                if (grid[i][j] == 1) {
                    q.push(i * n + j);
                    d[i][j] = 0;
                }
            }

        while (!q.empty()) {
            int ux = q.front() / n, uy = q.front() % n;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = ux + dx[i], y = uy + dy[i];
                if (x < 0 || x >= n || y < 0 || y >= n)
                    continue;

                if (d[x][y] > d[ux][uy] + 1) {
                    d[x][y] = d[ux][uy] + 1;
                    q.push(x * n + y);
                }
            }
        }
    }

    bool check(int m, const vector<vector<int>> &grid) {
        memset(v, false, sizeof(v));
        q.push(0);
        v[0][0] = true;

        while (!q.empty()) {
            int ux = q.front() / n, uy = q.front() % n;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = ux + dx[i], y = uy + dy[i];
                if (x < 0 || x >= n || y < 0 || y >= n || v[x][y])
                    continue;

                if (d[x][y] >= m) {
                    v[x][y] = true;
                    q.push(x * n + y);
                }
            }
        }

        return v[n - 1][n - 1];
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        bfs(grid);

        int l = 0, r = d[0][0];
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid + 1, grid)) l = mid + 1;
            else r = mid;
        }

        return l;
    }
};

作者：wzc1995
链接：https://www.acwing.com/solution/content/199248/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。