/**
 * 213. 打家劫舍 II
 * 不能偷相邻的房子，房子首尾相连
 * 
 * https://leetcode-cn.com/problems/house-robber-ii/
 */

class Solution {
public:
    // 动态规划，拆分成两个数组
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];

        return max(robMax(nums, 0, len-1), robMax(nums, 1, len));
    }

    int robMax(vector<int>& nums, int start, int end) {
        int pre_max = 0, cur_max = 0;
        int tmp = 0;        
        for(int i = start; i < end; i++) {
            tmp = cur_max;
            cur_max = max(pre_max + nums[i], cur_max);
            pre_max = tmp;
        }
        return cur_max;
    }
};
