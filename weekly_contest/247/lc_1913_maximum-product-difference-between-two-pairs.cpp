/**
 * 5797. 两个数对之间的最大乘积差
 * https://leetcode-cn.com/problems/maximum-product-difference-between-two-pairs/
 */

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        return nums[len-1] * nums[len-2] - nums[0] * nums[1];
    }
};
