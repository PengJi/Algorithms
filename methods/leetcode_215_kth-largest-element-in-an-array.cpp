/**
 * 215. 数组中的第K个最大元素
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 */

class Solution {
public:
    // 暴力法
    // 时间复杂度：O(nlogn)
    // 空间复杂度：O(1)
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        sort(begin(nums), end(nums));
        return nums[size - k];
    }
};
