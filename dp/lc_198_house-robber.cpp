/**
 * 198. 打家劫舍
 * https://leetcode-cn.com/problems/house-robber/
 */

class Solution {
public:
    // 动态规划
    // O(n)/O(n)
    int rob(vector<int>& nums) {
        int res = 0;
        int len = nums.size();
        if (len == 1) return nums[0];
        if (len == 2) return max(nums[0], nums[1]);

        vector<int> dp(len);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[len - 1];
    }

    // 动态规划（优化）
    // O(n)/O(1)
    int rob(vector<int>& nums) {
        int res = 0;
        int len = nums.size();
        if (len == 1) return nums[0];
        if (len == 2) return max(nums[0], nums[1]);

        int lastTwo = nums[0];
        int lastOne = max(nums[0], nums[1]);
        int curMax = 0;
        int tmp;

        for (int i = 2; i < len; i++) {
            tmp = lastOne;
            curMax = max(lastOne, lastTwo + nums[i]);
            lastOne = curMax;
            lastTwo = tmp;
        }

        return curMax;
    }
};
