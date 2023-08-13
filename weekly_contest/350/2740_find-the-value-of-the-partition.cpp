/**
 * 2740. 找出分区值
 * https://leetcode.cn/problems/find-the-value-of-the-partition/description/
 */

class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int n = nums.size();
        // 将序列排序
        sort(nums.begin(), nums.end());
        // 检查所有相邻元素，求最小差值
        int ans = nums[1] - nums[0];
        for (int i = 1; i < n; i++) ans = min(ans, nums[i] - nums[i - 1]);
        return ans;
    }
};
