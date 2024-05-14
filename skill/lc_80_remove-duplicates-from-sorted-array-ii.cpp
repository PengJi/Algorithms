/**
 * 80. 删除排序数组中的重复项 II
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;  // 有效索引
        for (auto x : nums) {
            if (k < 2 || nums[k - 2] != x) {
                nums[k++] = x;  // 有效数字增长
            }
        }

        return k;
    }
};
