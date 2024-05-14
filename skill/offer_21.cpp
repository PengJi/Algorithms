/**
 * 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
 * https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
 */

class Solution {
public:
    // 双指针
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    vector<int> exchange(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left < right) {
            if((nums[left] & 1) != 0) {
                left++;
                continue;
            }
            if((nums[right] & 1) != 1) {
                right--;
                continue;
            }
            swap(nums[left++], nums[right--]);
        }

        return nums;
    }
};
