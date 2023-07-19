/**
 * 2711. 对角线上不同值的数量差
 * https://leetcode.cn/problems/difference-of-number-of-distinct-values-on-diagonals
*/

const int N = 50;

class Solution {
private:
    int m, n;
    vector<vector<int>> ans;
    int sum[N + 10];
    bool seen[N + 10];

    void solve(int x, int y, const vector<vector<int>>& grid) {
        memset(sum, 0, sizeof(sum));
        memset(seen, false, sizeof(seen));

        int pre = 0, suf = 0;

        while (x < m && y < n) {
            if (sum[grid[x][y]] == 0)
                ++pre;
            ++sum[grid[x][y]];

            ++x; ++y;
        }

        --x; --y;
        while (x >= 0 && y >= 0) {
            if (sum[grid[x][y]] == 1)
                --pre;
            --sum[grid[x][y]];

            ans[x][y] = abs(pre - suf);

            if (!seen[grid[x][y]]) {
                ++suf;
                seen[grid[x][y]] = true;
            }

            --x; --y;
        }
    }

public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        ans.resize(m, vector<int>(n));

        for (int i = 0; i < m; i++)
            solve(i, 0, grid);

        for (int j = 1; j < n; j++)
            solve(0, j, grid);

        return ans;
    }
};
