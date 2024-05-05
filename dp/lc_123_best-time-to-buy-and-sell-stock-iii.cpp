/**
 * 123. 买卖股票的最佳时机 III
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(5, -100000);                           //-10000是因为前i个数最多进行i次操作，要区分可能进行的操作和不可能的
        dp[0] = 0;                                            //相当于dp[1][0]
        dp[1] = 0;                                            //相当于dp[1][1],初始资本为0.
        for (int i = 1; i < prices.size(); i++) {             // i数组索引
            for (int time = min(4, i + 1); time > 0; time--)  //必须倒序。
            {
                if (time % 2 == 1)
                    dp[time] = max(dp[time - 1], dp[time] + prices[i] - prices[i - 1]);
                else
                    dp[time] = max(dp[time - 1] + prices[i] - prices[i - 1], dp[time]);
            }
        }
        return max(dp[0], max(dp[2], dp[4]));  //进行0笔，1笔，2笔交易的最大值的最大值
    }
};

class Solution {
public:
    // 前后缀分解
    // 以 i 为分界点，i 为第二次买入的天
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int len = prices.size();
        vector<int> f(len);
        int minPrice = INT_MAX;

        // i 左边的最大值，记录在 f 数组中
        for (int i = 0; i < len; i++) {
            minPrice = min(minPrice, prices[i]);
            res = max(res, prices[i] - minPrice);
            f[i] = res;
        }

        // 计算 i 右边的最大值
        int maxPrice = INT_MIN;
        for (int i = len - 1; i >= 0; i--) {
            maxPrice = max(maxPrice, prices[i]);
            res = max(res, f[i] + maxPrice - prices[i]);
        }

        return res;
    }
};
