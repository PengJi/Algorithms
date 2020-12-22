/**
 * 581. 最短无序连续子数组
 * https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/
 */

class Solution {
public:
    // 双指针
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    // https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/solution/shi-jian-chao-guo-100de-javajie-fa-by-zackqf/
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        int right_bound = nums[0], left_bound = nums[len-1];
        int left = 0, right = -1;
        for(int i = 0; i < len; i++) {
            if(right_bound > nums[i]) {
                right = i;
            } else {
                right_bound = nums[i];
            }

            if(left_bound < nums[len-i-1]) {
                left = len - i - 1;
            } else {
                left_bound = nums[len-i-1];
            }
        }

        return right - left + 1;
    }
};
