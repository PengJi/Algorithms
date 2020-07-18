/**
 * 153. 寻找旋转排序数组中的最小值
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 请找出其中最小的元素。
 * 你可以假设数组中不存在重复元素。

 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/
 */

class Solution {
public:
    // 二分查找
    // 时间复杂度：O(logn)
    // 空间复杂度：O(1)
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;

        int left = 0, right = len-1;
        int mid;
        while(left < right) {
            mid = left + (right-left)/2;
            if(nums[mid] < nums[right])  // 在左半部分
                right = mid;
            else  // 在右半部分
                left = mid + 1;
        }

        return nums[left];
    }
};
