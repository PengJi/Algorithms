/**
 * 198. 打家劫舍
 * https://leetcode-cn.com/problems/house-robber/
 */

class Solution {
public:
    // 动态规划
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