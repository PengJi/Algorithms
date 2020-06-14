/**
 * 121. 买卖股票的最佳时机
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 */

class Solution {
public:
    // 暴力法（超时）
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(1)
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0) return 0;

        int max = 0, tmp;
        for(int i = 0; i < len; i++){
            for(int j = i+1; j < len; j++){
                if(prices[i] < prices[j]) tmp = prices[j] - prices[i];
                if(tmp > max) max = tmp;
            }
        }

        return max;
    }

    // 遍历一遍
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    int maxProfit(vector<int>& prices) {
        int minPrice = int(1e9);  // 截止到当天的最小股票价值
        int maxProfit = 0;  // 截止到当天的最大利润
        for(int i = 0; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }

    // 动态规划
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0) return 0;

        int minPrice = prices[0];
        vector<int> dp(len, 0);  // dp[i]表示前i天的最大利润
        for(int i = 1; i < len; i++){
            minPrice = min(minPrice, prices[i]);
            dp[i] = max(dp[i-1], prices[i] - minPrice);
        }

        return dp[len-1];
    }
};
