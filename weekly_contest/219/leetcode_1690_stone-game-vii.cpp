/**
 * 1690. 石子游戏 VII
 * https://leetcode-cn.com/problems/stone-game-vii/
 */

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int len = stones.size();
        vector<int> pre(len+1);
        for(int i = 0; i < len; i++) {
            pre[i+1] = pre[i] + stones[i];
        }

        vector<vector<int>> dp(len, vector<int>(len));
        for(int i = len-1; i >= 0; i--) {
            for(int j = i; j < len; j++) {
                if(i == j) {
                    dp[i][j] = 0;
                    continue;
                }
                int left = (pre[j+1] - pre[i+1]) - dp[i+1][j];
                int right = (pre[j] - pre[i]) - dp[i][j-1];
                dp[i][j] = max(left, right);
            }
        }

        return dp[0][len-1];
    }
};
