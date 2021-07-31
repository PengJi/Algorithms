/**
 * 283. 移动零
 * https://leetcode-cn.com/problems/move-zeroes/
 */

class Solution {
public:
    // 双指针
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        if(len == 0 || len == 1) return 0;

        int zero_idx = 0;
        for(int i = 0; i < len; i++) {
            if(nums[i] != 0) {
                tmp = nums[i];
                nums[i] = nums[zero_idx];
                nums[zero_idx] = tmp;
                zero_idx++;
            }
        }
    }

    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(auto x : nums) {
            if(x) nums[i++] = x;
        }
        while(i < nums.size()) nums[i++] = 0;
    }
};
