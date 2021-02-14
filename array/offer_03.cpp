/**
 * 剑指 Offer 03. 数组中重复的数字
 * https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
 */

class Solution {
public:
    // https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/solution/yuan-di-zhi-huan-shi-jian-kong-jian-100-by-derrick/
    int findRepeatNumber(vector<int>& nums) {
        int tmp;
        for(int i = 0 i < nums.size(); i++) {
            while(nums[i] != i) {
                if(nums[i] == nums[nums[i]]) {
                    return nums[i];
                }

                tmp = nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
        }

        return -1;
    }
};
