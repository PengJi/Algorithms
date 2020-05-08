/**
 * 198. 打家劫舍
 * https://leetcode-cn.com/problems/house-robber/
 */

class Solution {
public:
    // 动态规划
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;

        vector<int> dp(len+1);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i <= len; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }

        return dp[len];
    }

    // 动态规划（优化）
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;

        int prevMax = 0;
        int currMax = 0;
        for (int x : nums) {
            int temp = currMax;
            currMax = max(prevMax + x, currMax);
            prevMax = temp;
        }
        return currMax;
    }
};