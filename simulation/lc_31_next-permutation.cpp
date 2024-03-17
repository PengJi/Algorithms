/**
 * 31. 下一个排列
 * https://leetcode-cn.com/problems/next-permutation/
 */

class Solution {
public:
    // 找下一个排列就是从后往前寻找第一个出现降的地方，把这个地方的数字与后边某个比它大的的数字交换，再把该位置之后整理为升序。
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};
