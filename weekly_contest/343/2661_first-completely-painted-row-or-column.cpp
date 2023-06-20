/**
 * 2661. 找出叠涂元素
 * https://leetcode.cn/problems/first-completely-painted-row-or-column/
*/
class Solution {
public:
    // 哈希表
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        const int m = mat.size(), n = mat[0].size();

        vector<int> pos(m * n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                pos[mat[i][j] - 1] = i * n + j;

        vector<int> r(m, 0), c(n, 0);
        for (int i = 0; i < m * n; i++) {
            int x = pos[arr[i] - 1] / n;
            int y = pos[arr[i] - 1] % n;
            ++r[x];
            ++c[y];

            if (r[x] == n || c[y] == m)
                return i;
        }

        return -1;
    }
};
