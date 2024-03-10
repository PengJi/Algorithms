/**
 * 279. 完全平方数
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。
 * 你需要让组成和的完全平方数的个数最少。
 *
 * https://leetcode-cn.com/problems/perfect-squares/
 */

class Solution {
public:
    // 动态规划
    // https://leetcode-cn.com/problems/perfect-squares/solution/hua-jie-suan-fa-279-wan-quan-ping-fang-shu-by-guan/
    int numSquares(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = i;
            for (int j = 1; i - j * j >= 0; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};
