/**
 * 53. 最大子数组和
 * https://leetcode.cn/problems/maximum-subarray/
 */

class Solution {
public:
    // 动态规划
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) return nums[0];

        int res = nums[0];
        vector<int> dp(len);
        dp[0] = nums[0];  // 表示以 i 结尾的连续子数组的最大和

        for (int i = 1; i < len; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(res, dp[i]);
        }

        return res;
    }
};
