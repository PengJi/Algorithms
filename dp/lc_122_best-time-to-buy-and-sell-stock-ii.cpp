/**
 * 122. 买卖股票的最佳时机 II
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 * 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
 */

class Solution {
public:
    // 贪心
    // O(n)/O(1)
    int maxProfit(vector<int>& prices) {
        int res = 0;

        for (int i = 1; i < prices.size(); i++) {
            res += max(0, prices[i] - prices[i - 1]);
        }

        return res;
    }
};

class Solution {
public:
    // 动态规划
    // O(n)/O(n)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp0 = 0, dp1 = -prices[0];
        for (int i = 1; i < n; ++i) {
            int newDp0 = max(dp0, dp1 + prices[i]);
            int newDp1 = max(dp1, dp0 - prices[i]);
            dp0 = newDp0;
            dp1 = newDp1;
        }
        return dp0;
    }
};
