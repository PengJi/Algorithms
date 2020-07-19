/**
 * 152. 乘积最大子数组
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），
 * 并返回该子数组所对应的乘积。
 * 
 * https://leetcode-cn.com/problems/maximum-product-subarray/
 */

class Solution {
public:
    // 动态规划
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;

        int res = -2147483648;
        int tmpMax = 1, tmpMin = 1;
        for(int i = 0; i < len; i++){
            // 当负数出现时则max与min进行交换再进行下一步计算
            if(nums[i] < 0){
                swap(tmpMax, tmpMin);
            }

            // tmpMax为当前最大值
            tmpMax = max(tmpMax * nums[i], nums[i]);
            // 由于存在负数，那么会导致最大的变最小的，最小的变最大的。因此还需要维护当前最小值
            tmpMin = min(tmpMin * nums[i], nums[i]);  

            res = max(res, tmpMax);
        }

        return res;
    }
};
