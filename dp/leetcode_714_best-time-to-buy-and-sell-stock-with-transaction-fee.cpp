/**
 * 714. 买卖股票的最佳时机含手续费
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-han-shou-xu-fei-/
    int maxProfit(vector<int>& prices, int fee) {
        int ans = 0, hold = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            ans = max(ans, hold + prices[i] - fee);
            hold = max(hold, ans - prices[i]);
        }
        return ans;
    }
};
