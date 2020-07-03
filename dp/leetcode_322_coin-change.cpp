/**
 * 322. 零钱兑换
 * https://leetcode-cn.com/problems/coin-change/
 */

class Solution {
public:
    // 动态规划（自下而上）
    // 时间复杂度：O(amount * coins.size())
    // 空间复杂度：O(amount)
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        if(len == 0) return -1;

        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < coins.size(); j++) {
                if(i < coins[j]) continue;
                dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }

        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};
