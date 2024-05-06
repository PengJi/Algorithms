/**
 * 26. 删除排序数组中的重复项
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;  // 有效索引
        for (auto x : nums) {
            if (k == 0 || nums[k - 1] != x) {
                nums[k++] = x;  // 有效数字增长
            }
        }

        return k;
    }
};
