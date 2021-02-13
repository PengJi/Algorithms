/**
 * 剑指 Offer 49. 丑数
 * https://leetcode-cn.com/problems/chou-shu-lcof/
 */

class Solution {
public:
    // dp
    // https://leetcode-cn.com/problems/chou-shu-lcof/solution/chou-shu-ii-qing-xi-de-tui-dao-si-lu-by-mrsate/
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;  // 对应三个索引
        for(int i = 1; i < n; i++) {
            // 取最小值
            dp[i] = min(min(dp[p2] * 2, dp[p3] * 3), dp[p5] * 5);  // 状态转移
            if(dp[i] == dp[p2] * 2)
                p2++;
            if(dp[i] == dp[p3] * 3)
                p3++;
            if(dp[i] == dp[p5] * 5)
                p5++;
        }

        return dp[n-1];
    }
};
