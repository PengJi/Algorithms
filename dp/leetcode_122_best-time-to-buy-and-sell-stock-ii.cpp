/**
 * 122. 买卖股票的最佳时机 II
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
