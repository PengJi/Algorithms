/**
 * 209. 长度最小的子数组
 * 给定一个含有 n 个正整数的数组和一个正整数 s ，
 * 找出该数组中满足其和 ≥ s 的长度最小的子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。
 * 
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/
 */

class Solution {
public:
    // 双指针法
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int ans = INT_MAX;
        int start = 0, end = 0;
        int sum = 0;

        while (end < n) {
            sum += nums[end];
            while (sum >= s) {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};
