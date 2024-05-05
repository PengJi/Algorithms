/**
 * 188. 买卖股票的最佳时机 IV
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/solution/dong-tai-gui-hua-by-liweiwei1419-4/
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (k == 0 || len < 2) {
            return 0;
        }
        if (k >= len / 2) {
            return greedy(prices);
        }

        vector<vector<long>> dp(k + 1, vector<long>(2, 0));
        for (int i = 0; i <= k; i++) {
            dp[i][1] = INT_MIN;
        }
        for (int price : prices) {
            for (int j = 1; j <= k; j++) {
                dp[j][1] = max(dp[j][1], dp[j - 1][0] - price);
                dp[j][0] = max(dp[j][0], dp[j][1] + price);
            }
        }

        return dp[k][0];
    }

    int greedy(vector<int> prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                res += prices[i] - prices[i - 1];
            }
        }

        return res;
    }
};
