/**
 * 62. 不同路径
 * https://leetcode-cn.com/problems/unique-paths/
 */
class Solution {
public:
    // 动态规划（二维空间）
    // 状态表示：dp[i][j] 表示走到节点 [i, j] 的路径数
    // O(m * n)/O(m * n)
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m, vector<int>(n, 1));

        for (int i = 1; i < m; i++) {                 // 第一行的方案数为1
            for (int j = 1; j < n; j++) {             // 第一列的方案数为1
                f[i][j] = f[i][j - 1] + f[i - 1][j];  // 状态转移
            }
        }

        return f[m - 1][n - 1];
    }
};

class Solution {
public:
    // 动态规划（一维空间）
    // O(m * n)/O(min(m, n))
    int uniquePaths(int m, int n) {
        int small = min(m, n);
        int large = max(m, n);
        vector<int> dp(small, 1);

        for (int i = 1; i < large; i++) {
            for (int j = 1; j < small; j++) {
                dp[j] += dp[j - 1];
            }
        }

        return dp[small - 1];
    }
};
