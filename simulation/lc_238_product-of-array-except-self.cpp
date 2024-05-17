/**
 * 238. 除自身以外数组的乘积
 * https://leetcode-cn.com/problems/product-of-array-except-self/
 */

class Solution {
public:
    // 前缀积
    // 利用 output 数组当做临时存储空间，令 output[i] 为从 nums[0] * nums[1] * ... * num[i - 1]。
    // 然后从数组末尾，用变量 end 记录末尾若干数字的乘积，每次更新 output[i] 即可得到答案。
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1);
        for (int i = 1; i < n; i++)
            output[i] = output[i - 1] * nums[i - 1];

        int end = 1;
        for (int i = n - 1; i >= 0; i--) {
            output[i] *= end;
            end *= nums[i];
        }

        return output;
    }
};
