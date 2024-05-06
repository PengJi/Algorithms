/**
 * 283. 移动零
 * https://leetcode-cn.com/problems/move-zeroes/
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for (auto n : nums) {
            if (n) nums[k++] = n;
        }

        while (k < nums.size()) nums[k++] = 0;
    }
};
