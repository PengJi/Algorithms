/**
 * 2850. 将石头分散到网格图的最少移动次数
 * https://leetcode.cn/problems/minimum-moves-to-spread-stones-over-grid/description/
*/
class Solution {
private:
    inline int calc(const pair<int, int> &a, const pair<int, int> &b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    }

public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> s, t;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] == 0) t.emplace_back(i, j);
                while (grid[i][j] > 1) {
                    s.emplace_back(i, j);
                    --grid[i][j];
                }
            }

        int w = s.size();
        vector<int> f(1 << w, INT_MAX);
        f[0] = 0;

        for (int mask = 1; mask < (1 << w); mask++) {
            int k = 0;
            for (int i = 0; i < w; i++)
                if ((mask >> i) & 1)
                    ++k;

            for (int i = 0; i < w; i++)
                if ((mask >> i) & 1)
                    f[mask] = min(f[mask], f[mask ^ (1 << i)] + calc(s[k - 1], t[i]));
        }

        return f[(1 << w) - 1];
    }
};
