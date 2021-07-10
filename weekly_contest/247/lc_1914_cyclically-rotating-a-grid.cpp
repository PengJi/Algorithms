/**
 * 1914. 循环轮转矩阵
 * https://leetcode-cn.com/problems/cyclically-rotating-a-grid/
 */

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> res = grid;
        int n = grid.size(), m = grid[0].size();
        for (int a = n, b = m, i = 0; a > 0 && b > 0; a -= 2, b -= 2, i ++ ) {
            int x = i, y = i;
            vector<vector<int>> q;
            for (int j = 0; j < b - 1; j ++ ) q.push_back({x, ++ y});
            for (int j = 0; j < a - 1; j ++ ) q.push_back({ ++ x, y});
            for (int j = 0; j < b - 1; j ++ ) q.push_back({x, -- y});
            for (int j = 0; j < a - 1; j ++ ) q.push_back({ -- x, y});
            for (int j = 0; j < q.size(); j ++ ) {
                int t = (j + k) % q.size();
                res[q[j][0]][q[j][1]] = grid[q[t][0]][q[t][1]];
            }
        }
        return res;
    }
};
