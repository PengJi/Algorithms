/**
 * 31. 下一个排列
 * https://leetcode-cn.com/problems/next-permutation/
 */

class Solution {
public:
    // 找下一个排列就是从后往前寻找第一个出现降的地方，
    // 把这个地方的数字与后边某个比它大的的数字交换，再把该位置之后整理为升序。
    // 从数组末尾往前找，找到 第一个 位置 j，使得 nums[j] < nums[j + 1]。
    // 如果不存在这样的 j，则说明数组是不递增的，直接将数组逆转即可。
    // 如果存在这样的 j，则从末尾找到第一个位置 i > j，使得 nums[i] > nums[j]。
    // 交换 nums[i] 与 nums[j]，然后将数组从 j + 1 到末尾部分逆转。
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int j = -1;
        for (int i = n - 2; i >= 0; i--)
            if (nums[i] < nums[i + 1]) {
                j = i;
                break;
            }

        if (j == -1)
            reverse(nums.begin(), nums.end());
        else {
            for (int i = n - 1; i > j; i--)
                if (nums[i] > nums[j]) {
                    swap(nums[i], nums[j]);
                    break;
                }
            reverse(nums.begin() + j + 1, nums.end());
        }
    }
};
