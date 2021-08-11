/**
 * 81. 搜索旋转排序数组 II
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/
 */

class Solution {
public:
    // https://www.acwing.com/solution/content/6387/
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        int l = 0;

        int t = nums.size() - 1;
        while (t > 0 && nums[t] == nums[0]) t -- ;

        int r = t;
        // 找到最小值
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] <= nums[t]) r = mid;
            else l = mid + 1;
        }

        if (target <= nums[t]) r = t; // 答案在右半边
        else l = 0, r -- ; // 答案在左半边

        // 搜索答案，直接套模板
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }

        return nums[l] == target;
    }
};
