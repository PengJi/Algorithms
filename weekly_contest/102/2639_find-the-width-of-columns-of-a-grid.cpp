/**
 * 2639. 查询网格图中每一列的宽度
 * https://leetcode.cn/problems/find-the-width-of-columns-of-a-grid/description/
*/
class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();

        vector<int> ans(n, 0);
        for (int j = 0; j < n; j++)
            for (int i = 0; i < m; i++)
                ans[j] = max(ans[j], int(to_string(grid[i][j]).size()));

        return ans;
    }
};
