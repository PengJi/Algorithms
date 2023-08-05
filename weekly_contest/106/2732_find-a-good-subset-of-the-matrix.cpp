/**
 * 2732. 找到矩阵中的好子集
 * https://leetcode.cn/problems/find-a-good-subset-of-the-matrix/description/
*/

class Solution {
private:
    vector<int> get_ans(int x, int y) {
        if (x < y)
            return {x, y};

        return {y, x};
    }

public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();

        vector<int> seen(1 << n, -1);
        for (int i = 0; i < m; i++) {
            int r = 0;
            for (int j = 0; j < n; j++)
                r |= grid[i][j] << j;

            seen[r] = i;
        }

        if (seen[0] != -1)
            return {seen[0]};

        for (int i = 1; i < (1 << n) - 1; i++) {
            if (seen[i] == -1)
                continue;

            int s = (1 << n) - 1 - i;
            for (int j = s; j > 0; j = (j - 1) & s)
                if (seen[j] != -1)
                    return get_ans(seen[i], seen[j]);
        }

        return {};
    }
};
