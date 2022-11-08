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

class Solution {
public:
    // 状态表示：dp[i]记录以 nums[i] 结尾（即nums[i]为最后一个数字）的最长递增子序列的长度。
    // 初始状态：dp[0] = 1
    // 状态转移：dp[i]=max(dp[j]+1)，其中要求 1≤j<i 且 nums[j]<nums[i]。
    // 时间复杂度为 O(n^2)，对于每个 i，都需要从 1 遍历到 i。
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 1);
        int res = 1;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }

            if(dp[i] > res) res = dp[i];
        }

        return res;
    }
};
