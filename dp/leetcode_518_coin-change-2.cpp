/**
 * 518. 零钱兑换 II
 * 给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 
 * 
 * https://leetcode-cn.com/problems/coin-change-2/
 */

class Solution {
public:
    // 动态规划
    // https://leetcode-cn.com/problems/coin-change-2/solution/ling-qian-dui-huan-iihe-pa-lou-ti-wen-ti-dao-di-yo/
    // 时间复杂度：O(amount * coins.size())
    // 空间复杂度：O(amount)
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        // if(len == 0) return 0;

        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int i = 0; i < len; i++) {
            for(int j = 1; j <= amount; j++) {
                if(j < coins[i]) continue;
                dp[j] += dp[j-coins[i]];
            }
        }

        return dp[amount];
    }
};
