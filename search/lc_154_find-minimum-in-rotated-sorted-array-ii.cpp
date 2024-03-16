/**
 * 154. 寻找旋转排序数组中的最小值 II
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/
 */

class Solution {
public:
    // https://www.acwing.com/solution/content/6386/
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r && nums[r] == nums[0]) r--;
        if (nums[l] <= nums[r]) return nums[0];

        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] < nums[0])
                r = mid;
            else
                l = mid + 1;
        }

        return nums[r];
    }
};
