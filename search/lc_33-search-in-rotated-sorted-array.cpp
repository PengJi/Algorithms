/**
 * 33. 搜索旋转排序数组
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid;
        int left = 0, right = nums.size()-1;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return mid;
            }
            
            if(nums[left] <= nums[mid]){  // 左边递增
                if(nums[left] <= target && target < nums[mid]){
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {  // 右边递增
                if(nums[mid] < target && target <= nums[right]){
                    left = mid + 1;
                } else {
                    right = mid -1;
                }
            }
        }

        return -1;
    }
};
