/**
 * 416. 分割等和子集
 * 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 *
 * https://leetcode-cn.com/problems/partition-equal-subset-sum/
 */

class Solution {
public:
    // 动态规划
    // 时间复杂度：O(n*sum)
    // 空间复杂度：O(sum)
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int num : nums) sum += num;
        if (sum % 2 != 0) return false;

        sum = sum / 2;
        vector<bool> dp(sum + 1, false);
        // base case
        dp[0] = true;

        for (int i = 0; i < n; i++)
            for (int j = sum; j >= 0; j--)
                if (j - nums[i] >= 0)
                    dp[j] = dp[j] || dp[j - nums[i]];

        return dp[sum];
    }
};
