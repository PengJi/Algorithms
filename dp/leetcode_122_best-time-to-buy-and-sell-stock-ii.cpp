/**
 * 122. 买卖股票的最佳时机 II
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 * 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
 */

class Solution {
public:
    // 遍历
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <= 1) return 0;

        int res;
        for(int i = 1; i < len; i++) {
            if(prices[i] > prices[i-1]) res += prices[i] - prices[i-1];
        }

        return res;
    }
};
