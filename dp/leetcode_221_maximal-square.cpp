/**
 * 221. 最大正方形
 * https://leetcode-cn.com/problems/maximal-square/
 */

class Solution {
public:
    // 动态规划
    // 时间复杂度：O(mn)
    // 空间复杂度：O(n)
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }

        int m = matrix.size(), n = matrix[0].size(), sz = 0, pre;
        vector<int> cur(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int temp = cur[j];
                if (i==0 || j==0 || matrix[i][j]=='0') {
                    cur[j] = matrix[i][j] - '0';
                } else {
                    cur[j] = min(pre, min(cur[j], cur[j - 1])) + 1;
                }
                sz = max(cur[j], sz);
                pre = temp;
            }
        }
        return sz * sz;
    }
};