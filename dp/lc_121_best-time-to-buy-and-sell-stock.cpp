/**
 * 121. 买卖股票的最佳时机
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 * 如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 */

class Solution {
public:
    // 遍历
    // O(n)/O(1)
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  // 截止到当天的最小股票价值
        int res = 0;             // 截止到当天的最大利润

        for (auto& p : prices) {
            minPrice = min(minPrice, p);
            res = max(res, p - minPrice);
        }

        return res;
    }
};

class Solution {
public:
    // 动态规划
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int minPrice = prices[0];

        vector<int> dp(len, 0);  // dp[i]表示前i天的最大利润
        for (int i = 1; i < len; i++) {
            minPrice = min(minPrice, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - minPrice);  // 状态转移
        }

        return dp[len - 1];
    }
};
