/**
 * 300. 最长上升子序列
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 * 
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/
 */

class Solution {
public:
    // 动态规划
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(n)
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) { 
            return 0; 
        } 
        
        // 表示最长上升子序列的长度
        vector<int> dp(size, 1);
        int res = 1;
        for (int i = 1; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
