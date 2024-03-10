/**
 * 494. 目标和
 * https://leetcode-cn.com/problems/target-sum/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/target-sum/solution/c-dfshe-01bei-bao-by-bao-bao-ke-guai-liao/
    int findTargetSumWays(vector<int> &nums, int S) {
        long sum = 0;
        for (const int &it : nums) {
            sum += it;
        }
        if ((S + sum) % 2 == 1 || S > sum) {
            return 0;
        }
        S = (S + sum) / 2;
        int *dp = new int[S + 1];
        memset(dp, 0, (S + 1) * sizeof(int));
        dp[0] = 1;
        for (const int &it : nums) {
            for (int j = S; j >= it; j--)
                dp[j] += dp[j - it];
        }
        int ans = dp[S];
        delete[] dp;
        return ans;
    }
};
